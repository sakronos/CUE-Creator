#include <io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printDir( const char* path )
{
    struct _finddata_t data;
    long hnd = _findfirst( path, &data );    // �����ļ�����������ʽchRE��ƥ���һ���ļ�
    if ( hnd < 0 )
    {
        perror( path );
    }
    int  nRet = (hnd <0 ) ? -1 : 1;

    FILE *fp2;
             if((fp2=fopen("info.txt","r"))==NULL)     //�ȸ�Ϊ������ļ����ٽ����еľ���д�����ļ�
             {
                 printf("cannot open file \n");
                 exit(0);
             }

             fclose(fp2);
    while ( nRet >= 0 )
    {
        char n1[50];
        strcpy(n1,data.name);
        strcat(n1,".cue");
        FILE *fp;
             if((fp=fopen(n1,"w"))==NULL)
             {
                 printf("cannot open file \n");
                 exit(0);
             }
             fputs("FILE \"",fp);
             fputs(data.name,fp);
             fputs("\" WAVE\n",fp);
             fputs("  TRACK 01 AUDIO\n",fp);
             fputs("    TITLE \"",fp);
        fclose(fp);
        //printf("%s\n", data.name );
        nRet = _findnext( hnd, &data );
    }
    _findclose( hnd );     // �رյ�ǰ���
}
/*void main()
{
    printDir("d:/C/T/*.*");
}

int main(int argc,char *argv[])
{
    printf(argv[0]);
    printDir("d:/C/T/*.*");
    return 0;
}*/

int main(int argc,char *argv[])
{
    char ch[300],ch0[10];
    strcpy(ch,argv[0]);
    char *p=ch;
    while(*p)
        p++;
    p--;
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p--='\0';
    *p='\0';
    strcpy(ch0,"*.wav");
    strcat(ch,ch0);
    printDir(ch);
    system("pause");
    return 0;
}

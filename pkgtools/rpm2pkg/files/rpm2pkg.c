/*

	$NetBSD: rpm2pkg.c,v 1.1.1.1 2001/01/25 08:57:53 tron Exp $

*/

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <cpio.h>
#include <rpmlib.h>
#include <zlib.h>

char CPIOMagic[] = {'0','7','0','7','0','1'};

#define CPIO_END_MARKER		"TRAILER!!!"
#define CPIO_FIELD_LENGTH	8

#define CPIO_HDR_MODE		1
#define CPIO_HDR_FILESIZE	6
#define CPIO_HDR_NAMESIZE	11
#define CPIO_NUM_HEADERS	13

#define CP_IFMT			0170000

#define TRUE  1
#define FALSE 0

#define GZREAD(s,b,l) (gzread((s),(b),(l))==l)

extern char *__progname;

struct ModeMap
 {
  long   mm_CPIOMode;
  mode_t mm_SysMode;
 };
struct ModeMap ModeMapTab[] =
 {
  {C_IRUSR,S_IRUSR},
  {C_IWUSR,S_IWUSR},
  {C_IXUSR,S_IXUSR},
  {C_IRGRP,S_IRGRP},
  {C_IWGRP,S_IWGRP},
  {C_IXGRP,S_IXGRP},
  {C_IROTH,S_IROTH},
  {C_IWOTH,S_IWOTH},
  {C_IXOTH,S_IXOTH},
  {C_ISUID,S_ISUID},
  {C_ISGID,S_ISGID},
  {C_ISVTX,S_ISVTX},
  {0,0}
 };

typedef struct PListEntryStruct PListEntry;
struct PListEntryStruct
 {
  PListEntry *pe_Childs[2];
  int pe_DirEmpty;
  mode_t pe_DirMode;
  char *pe_Link;
  char pe_Name[1];
 };

#define pe_Left  pe_Childs[0]
#define pe_Right pe_Childs[1]

typedef void PListEntryFunc(PListEntry *,FILE *);

#define PLIST_ORDER_FORWARD  0
#define PLIST_ORDER_BACKWARD 1

PListEntry *InsertPListEntry(PListEntry **Tree,char *Name)

{
 PListEntry *Node;

 while ((Node=*Tree)!=NULL)
  Tree=&((strcmp(Name,Node->pe_Name)<0)?Node->pe_Left:Node->pe_Right);

 if ((Node=malloc(sizeof(PListEntry)+strlen(Name)))==NULL)
  {
   perror(__progname);
   exit(EXIT_FAILURE);
  }

 Node->pe_Left=NULL;
 Node->pe_Right=NULL;
 Node->pe_DirEmpty=FALSE;
 Node->pe_Link=NULL;
 (void)strcpy(Node->pe_Name,Name);

 return *Tree=Node;
}

PListEntry *FindPListEntry(PListEntry *Tree,char *Name)

{
 while (Tree!=NULL)
  {
   int Result;

   if ((Result=strcmp(Name,Tree->pe_Name))==0) break;
   Tree=(Result<0)?Tree->pe_Left:Tree->pe_Right;
  }

 return Tree;
}

void PListEntryFile(PListEntry *Node,FILE *Out)

{
 (void)fputs(Node->pe_Name,Out);
 (void)fputc('\n',Out);
}

void PListEntryLink(PListEntry *Node,FILE *Out)

{
 (void)fprintf(Out,"@exec ln -fs %s %%D/%s\n",Node->pe_Link,Node->pe_Name);
 (void)fprintf(Out,"@unexec rm -f %%D/%s\n",Node->pe_Name);
}

void PListEntryMakeDir(PListEntry *Node,FILE *Out)

{
 if (Node->pe_DirEmpty)
  (void)fprintf(Out,
                "@exec mkdir -m %o -p %%D/%s\n",
                Node->pe_DirMode,
                Node->pe_Name);
}

void PListEntryRemoveDir(PListEntry *Node,FILE *Out)

{
 (void)fprintf(Out,"@dirrm %s\n",Node->pe_Name);
}

void ProcessPList(PListEntry *Tree,PListEntryFunc Func,int Order,FILE *Out)

{
 while (Tree!=NULL)
  {
   if (Tree->pe_Childs[Order]!=NULL)
    ProcessPList(Tree->pe_Childs[Order],Func,Order,Out);
   Func(Tree,Out);
   Tree=Tree->pe_Childs[1-Order];
  }
}

char **ArrayAdd(char **Array,char *String)

{
 int Old;

 Old=0;
 if (Array!=NULL) while (Array[Old]!=NULL) Old++;
 if ((Array=realloc(Array,sizeof(char *)*(Old+2)))==NULL) return NULL;

 Array[Old++]=String;
 Array[Old]=NULL;

 return Array;
}

void Usage(void)

{
 (void)fprintf(stderr,
               "Usage: %s [-d directory] [-f packlist] [[-i ignorepath] ...]\n"
               "               [-p prefix] rpmfile [...]\n",
               __progname);
 exit(EXIT_FAILURE);
}

int SkipAndAlign(gzFile In,long Skip)

{
 z_off_t Pos,NewPos;

 if ((Pos=gztell(In))<0) return FALSE;

 NewPos=(Pos+Skip+3)&(~3);
 return ((Pos==NewPos)||(gzseek(In,NewPos,SEEK_SET)==NewPos));
}

char *GetData(gzFile In,long Length)

{
 char *Ptr;

 if ((Ptr=malloc(Length+1))!=NULL)
  {
   if (GZREAD(In,Ptr,Length)&&SkipAndAlign(In,0))
    {
     Ptr[Length]='\0';
     return Ptr;
    }
   free(Ptr);
  }

 return NULL;
}

int GetCPIOHeader(gzFile In,long *Fields,char **Name)

{
 char Buffer[CPIO_NUM_HEADERS*CPIO_FIELD_LENGTH];
 char *Ptr;
 int Index;
 long Value;

 *Name=NULL;

 if (!GZREAD(In,Buffer,sizeof(CPIOMagic))) return FALSE;
 if (memcmp(Buffer,CPIOMagic,sizeof(CPIOMagic))!=0) return FALSE;

 if (gzread(In,Buffer,sizeof(Buffer))!=sizeof(Buffer)) return FALSE;
 Ptr=Buffer;
 Index=sizeof(Buffer);
 Value=0;
 while (Index-->0)
  {
   Value<<=4;
   if ((*Ptr>='0')&&(*Ptr<='9')) Value+=(long)(*Ptr++-'0');
   else
    if ((*Ptr>='A')&&(*Ptr<='F')) Value+=(long)(*Ptr++-'A')+10;
    else
     if ((*Ptr>='a')&&(*Ptr<='f')) Value+=(long)(*Ptr++-'a')+10;
     else return FALSE;
   
   if ((Index%CPIO_FIELD_LENGTH)==0)
    {
     *Fields++=Value;
     Value=0;
    }
  }

 Value=Fields[CPIO_HDR_NAMESIZE-CPIO_NUM_HEADERS];
 if ((*Name=GetData(In,Value))==NULL) return FALSE;
 return ((*Name)[Value-1]=='\0');
}

mode_t ConvertMode(long CPIOMode)

{
 mode_t Mode;
 int Index;

 Mode=0;
 Index=0;
 while (ModeMapTab[Index].mm_CPIOMode!=0)
  {
   if ((CPIOMode&ModeMapTab[Index].mm_CPIOMode)!=0)
    Mode|=ModeMapTab[Index].mm_SysMode;
   Index++;
  }

 return Mode;
}

int MakeTargetDir(char *Name,PListEntry **Dirs,int MarkNonEmpty)

{
 char *Basename;
 PListEntry *Dir;
 struct stat Stat;
 int Result;

 if ((Basename=strrchr(Name,'/'))==NULL) return TRUE;

 *Basename='\0';
 if ((Dir=FindPListEntry(*Dirs,Name))!=NULL)
  {
   *Basename='/';
   Dir->pe_DirEmpty=!MarkNonEmpty;
   return TRUE;
  }

 if (!MakeTargetDir(Name,Dirs,TRUE))
  {
   *Basename='/';
   return FALSE;
  }

 if (stat(Name,&Stat)==0) Result=S_ISDIR(Stat.st_mode);
 else
  if (errno!=ENOENT) Result=FALSE;
  else
   if ((Result=(mkdir(Name,S_IRWXU|S_IRWXG|S_IRWXO)==0)))
    InsertPListEntry(Dirs,Name)->pe_DirMode=S_IRWXU|S_IRWXG|S_IRWXO;

 *Basename='/';
 return Result;
}

char *StrCat(char *Prefix,char *Suffix)

{
 int Length;
 char *Str;

 Length=strlen(Prefix);
 if ((Str=malloc(Length+strlen(Suffix)+1))!=NULL)
  {
   (void)memcpy(Str,Prefix,Length);
   (void)strcpy(&Str[Length],Suffix);
  }
 return Str;
}

int MakeDir(char *Name,mode_t Mode,int *OldDir)

{
 struct stat Stat;

 *OldDir=FALSE;
 if (mkdir(Name,Mode)==0) return TRUE;

 if ((errno!=EEXIST)||
     (lstat(Name,&Stat)<0)||
     !S_ISDIR(Stat.st_mode)) return FALSE;

 *OldDir=TRUE;
 return TRUE;
}

int MakeSymLink(char *Link,char *Name)

{
 struct stat Stat;

 if (symlink(Link,Name)==0) return TRUE;

 if ((errno!=EEXIST)||
     (lstat(Name,&Stat)<0)||
     !S_ISLNK(Stat.st_mode)) return FALSE;

 return ((unlink(Name)==0)&&(symlink(Link,Name)==0));
}

int WriteFile(gzFile In,char *Name,mode_t Mode,long Length)

{
 int Out;
 struct stat Stat;
 static void *Buffer=NULL;
 static long BufferSize=0;

 if (lstat(Name,&Stat)==0)
  if (!S_ISREG(Stat.st_mode)||(unlink(Name)<0)) return FALSE;

 if (Buffer==NULL)
  {
   BufferSize=sysconf(_SC_PAGESIZE)*256;
   if ((Buffer=malloc(BufferSize))==NULL) return FALSE;
  }

 if ((Out=open(Name,O_WRONLY|O_CREAT,Mode))<=0) return FALSE;

 while (Length>0)
  {
   long Chunk;

   Chunk=(Length>BufferSize)?BufferSize:Length;
   if (!GZREAD(In,Buffer,Chunk)) break;
   if (write(Out,Buffer,Chunk)!=Chunk) break;
   Length-=Chunk;
  }

 if ((close(Out)==0)&&(Length==0)) return SkipAndAlign(In,0);

 (void)unlink(Name);
 return FALSE;
}

void CheckSymLinks(PListEntry **Links,PListEntry **Files,PListEntry **Dirs)

{
 PListEntry *Link;
 struct stat Stat;

 while ((Link=*Links)!=NULL)
  {
   PListEntry *Ptr;
   char *Basename;

   if (Link->pe_Left!=NULL)
    CheckSymLinks(&Link->pe_Left,Files,Dirs);

   if ((stat(Link->pe_Name,&Stat)<0)||!S_ISREG(Stat.st_mode))
    {
     Links=&Link->pe_Right;
     continue;
    }

   (void)InsertPListEntry(Files,Link->pe_Name);
   if ((Basename=strrchr(Link->pe_Name,'/'))!=NULL)
    {
     *Basename='\0';
     if ((Ptr=FindPListEntry(*Dirs,Link->pe_Name))!=NULL)
      Ptr->pe_DirEmpty=FALSE;
    }

   if (Link->pe_Right==NULL)
    {
     *Links=Link->pe_Left;
     free(Link);
     break;
    }

   *Links=Link->pe_Right;
   Ptr=Link->pe_Left;
   free(Link);

   if (Ptr==NULL) continue;

   Link=*Links;
   while (Link->pe_Left!=NULL) Link=Link->pe_Left;
   Link->pe_Left=Ptr;
  }
}

int main(int argc,char **argv)

{
 FILE *PList;
 char **Ignore,*Prefix;
 int Opt,Index,FD,IsSource;
 PListEntry *Files,*Links,*Dirs;
 Header Hdr;
 gzFile In;

 PList=NULL;
 Ignore=NULL;
 Prefix=NULL;
 while ((Opt=getopt(argc,argv,"d:f:i:p:"))!=-1)
  switch (Opt)
   {
    case 'f':
     if (PList!=NULL) (void)fclose(PList);
     if ((PList=fopen(optarg,"a"))==NULL)
      {
       perror(optarg);
       return EXIT_FAILURE;
      }
     break;
    case 'i':
     if ((Ignore=ArrayAdd(Ignore,optarg))==NULL)
      {
       perror(__progname);
       exit(EXIT_FAILURE);
      }
     break;
    case 'd':
     if (chdir(optarg))
      {
       perror(optarg);
       return EXIT_FAILURE;
      }
     break;
    case 'p':
     Prefix=optarg;
     break;
    default:
     Usage();
   }

 if (Prefix!=NULL)
  {
   int Length;

   Length=strlen(Prefix);
   if (Length==0) Prefix=NULL;
   else
    if ((Prefix[Length-1]!='/')&&((Prefix=StrCat(Prefix,"/"))==NULL))
     {
      perror(__progname);
      exit(EXIT_FAILURE);
     }
  }

 argc-=optind;
 argv+=optind;
 if (argc==0) Usage();

 Files=NULL;
 Links=NULL;
 Dirs=NULL;
 for (Index=0; Index<argc; Index++)
  {
   if ((FD=open(argv[Index],O_RDONLY,0))<0)
    {
     perror(argv[Index]);
     return EXIT_FAILURE;
    }

   switch (rpmReadPackageHeader(FD,&Hdr,&IsSource,NULL,NULL))
    {
     case 0:
      break;
     case 1:
      (void)fprintf(stderr,"%s: file is not an RPM package.\n",argv[Index]);
      return EXIT_FAILURE;
     default:
      (void)fprintf(stderr,"%s: error reading header.\n",argv[Index]);
      return EXIT_FAILURE;
    }

   if ((In=gzdopen(FD,"r"))==NULL)
    {
     (void)fprintf(stderr,"%s: cannot read cpio data.\n",argv[Index]);
     return EXIT_FAILURE;
    }

   for (;;)
    {
     long Fields[CPIO_NUM_HEADERS];
     char *Name;
     mode_t Mode;
     long Length;

     if (!GetCPIOHeader(In,Fields,&Name))
      {
       (void)fprintf(stderr,"%s: error in cpio header.\n",argv[Index]);
       return EXIT_FAILURE;
      }
     if (strcmp(Name,CPIO_END_MARKER)==0)
      {
       free(Name);
       break;
      }
     if (*Name=='\0') Fields[CPIO_HDR_MODE]=0;

     if (Ignore!=NULL)
      {
       char **Ptr;

       Ptr=Ignore;
       while (*Ptr!=NULL)
        {
         int Length;

         Length=strlen(*Ptr);
         if ((strncmp(*Ptr,Name,Length)==0)&&
             ((Name[Length]=='\0')||(Name[Length]=='/'))) break;
         else Ptr++;
        }
       if (*Ptr!=NULL) Fields[CPIO_HDR_MODE]=0;
      }

     if (Prefix!=NULL)
      {
       char *Fullname;

       if ((Fullname=StrCat(Prefix,Name))==NULL)
        {
        perror(__progname);
        exit(EXIT_FAILURE);
        }
       free(Name);
       Name=Fullname;
      }

     Mode=ConvertMode(Fields[CPIO_HDR_MODE]);
     Length=Fields[CPIO_HDR_FILESIZE];
     switch (Fields[CPIO_HDR_MODE]&CP_IFMT)
      {
       case C_ISDIR:
        {
         PListEntry *Dir;
         int OldDir;

         if (Length!=0)
          {
           (void)fprintf(stderr,"%s: error in cpio file.\n",argv[Index]);
           return EXIT_FAILURE;
          }
         if (!MakeTargetDir(Name,&Dirs,TRUE))
          {
           (void)fprintf(stderr,
                         "%s: can't create parent directories for \"%s\".\n",
                         argv[Index],
                         Name);
           return EXIT_FAILURE;
          }

         if (!MakeDir(Name,Mode,&OldDir))
          {
           (void)fprintf(stderr,
                         "%s: can't create directory \"%s\".\n",
                         argv[Index],
                         Name);
           return EXIT_FAILURE;
          }

         if (!OldDir)
          {
           Dir=InsertPListEntry(&Dirs,Name);
           Dir->pe_DirEmpty=TRUE;
           Dir->pe_DirMode=Mode;
          }
         break;
        }
       case C_ISLNK:
        {
         char *Link;
         struct stat Stat;

         if ((Link=GetData(In,Length))==NULL)
          {
           (void)fprintf(stderr,"%s: error in cpio file.\n",argv[Index]);
           return EXIT_FAILURE;
          }

         if (!MakeTargetDir(Name,&Dirs,FALSE))
          {
           (void)fprintf(stderr,
                         "%s: can't create parent directories for \"%s\".\n",
                         argv[Index],
                         Name);
           return EXIT_FAILURE;
          }

         if (*Link=='/')
          {
           char *Ptr;

           (void)strcpy(Link,Link+1);
           Ptr=Name;
           if (Prefix!=NULL) Ptr+=strlen(Prefix);
           while ((Ptr=strchr(Ptr,'/'))!=NULL)
            {
             char *NewLink;

             if ((NewLink=StrCat("../",Link))==NULL)
              {
               perror(__progname);
               return EXIT_FAILURE;
              }
             free(Link);
             Link=NewLink;

             Ptr++;
            }
          }
         if (!MakeSymLink(Link,Name))
          {
           (void)fprintf(stderr,
                         "%s: can't create symbolic link \"%s\".\n",
                         argv[Index],
                         Name);
           return EXIT_FAILURE;
          }

         InsertPListEntry(&Links,Name)->pe_Link=Link;
         break;
        }
       case C_ISREG:
        if (!MakeTargetDir(Name,&Dirs,TRUE))
         {
          (void)fprintf(stderr,
                        "%s: can't create parent directories for \"%s\".\n",
                        argv[Index],
                        Name);
          return EXIT_FAILURE;
         }
        if (!WriteFile(In,Name,Mode,Length))
         {
          (void)fprintf(stderr,
                        "%s: can't write file \"%s\".\n",
                        argv[Index],
                        Name);
          return EXIT_FAILURE;
         }
        (void)InsertPListEntry(&Files,Name);
        break;
       default:
        if ((Length>0)&&(gzseek(In,(Length+3)&(~3),SEEK_CUR)<0)) break;
      }

     free(Name);
    }

   (void)gzclose(In);
   (void)close(FD);
  }

 if (PList!=NULL)
  {
   ProcessPList(Files,PListEntryFile,PLIST_ORDER_FORWARD,PList);
   ProcessPList(Dirs,PListEntryMakeDir,PLIST_ORDER_FORWARD,PList);
   ProcessPList(Links,PListEntryLink,PLIST_ORDER_FORWARD,PList);
   ProcessPList(Dirs,PListEntryRemoveDir,PLIST_ORDER_BACKWARD,PList);
   (void)fclose(PList);
  }

 return EXIT_SUCCESS;
}


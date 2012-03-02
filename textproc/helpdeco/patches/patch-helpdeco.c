$NetBSD: patch-helpdeco.c,v 1.1 2012/03/02 12:11:01 hans Exp $

--- helpdeco.c.orig	2005-11-18 12:08:36.000000000 +0100
+++ helpdeco.c	2012-03-02 13:03:23.013470516 +0100
@@ -32,8 +32,8 @@ http://www.gnu.org
 */
 
 FILEREF *external;
-char HelpFileName[NAME_MAX];
-char name[NAME_MAX];
+char HelpFileName[FILENAME_MAX];
+char name[FILENAME_MAX];
 char ext[_MAX_EXT];
 FILE *AnnoFile;
 HASHREC *hashrec;
@@ -74,7 +74,7 @@ int NextKeywordRec,KeywordRecs;
 KEYWORDREC *KeywordRec;
 TOPICOFFSET NextKeywordOffset;
 char helpcomp[13];
-char HelpFileTitle[NAME_MAX];
+char HelpFileTitle[FILENAME_MAX];
 char TopicTitle[256];
 char *Phrases;
 unsigned int *PhraseOffsets;
@@ -607,7 +607,7 @@ void SysLoad(FILE *HelpFile) /* gets glo
 /* compares filename a[.HLP] and filename b[.HLP], returning 0 if match */
 int filenamecmp(const char *a,const char *b)
 {
-    char aname[NAME_MAX],bname[NAME_MAX];
+    char aname[FILENAME_MAX],bname[FILENAME_MAX];
     char aext[_MAX_EXT],bext[_MAX_EXT];
     int i;
 
@@ -5597,7 +5597,7 @@ BOOL HelpDeCompile(FILE *HelpFile,char *
 
 int main(int argc,char *argv[])
 {
-    char AnnoFileName[NAME_MAX];
+    char AnnoFileName[FILENAME_MAX];
     char drive[_MAX_DRIVE];
     char dir[PATH_MAX];
     FILE *f;

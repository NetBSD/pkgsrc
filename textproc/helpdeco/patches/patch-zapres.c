$NetBSD: patch-zapres.c,v 1.1 2012/03/02 12:11:01 hans Exp $

--- zapres.c.orig	2005-11-17 11:56:32.000000000 +0100
+++ zapres.c	2012-03-02 13:00:45.979797155 +0100
@@ -36,13 +36,13 @@ will not rescale the image and MRBC can 
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 #include <string.h>
 #include "compat.h"
 
 int backup(FILE *f,char *oldname)
 {
-    char drive[_MAX_DRIVE],dir[PATH_MAX],fname[NAME_MAX],ext[_MAX_EXT];
+    char drive[_MAX_DRIVE],dir[PATH_MAX],fname[FILENAME_MAX],ext[_MAX_EXT];
     char path[PATH_MAX];
     char buffer[512];
     long pos,size;
@@ -92,7 +92,7 @@ int main(int argc,char *argv[])
     FILE *f;
     int b,n,i,k,bb;
     long w,h,zero,pos;
-    char drive[_MAX_DRIVE],dir[PATH_MAX],fname[NAME_MAX],ext[_MAX_EXT];
+    char drive[_MAX_DRIVE],dir[PATH_MAX],fname[FILENAME_MAX],ext[_MAX_EXT];
     char path[PATH_MAX];
 
     for(b=i=1;i<argc;i++)

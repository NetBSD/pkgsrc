$NetBSD: patch-SRC_dqs__setenv.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_setenv.c.orig	2013-03-28 16:20:07.000000000 +0000
+++ SRC/dqs_setenv.c
@@ -70,11 +70,7 @@ static char dqs_setenv_rcsid[]="$Id: dqs
 extern char **environ;
 
 /*****************************************************************************/
-int dqs_setenv(name,value,overwrite)
-     char *name;
-     char *value;
-     int  overwrite;
-     
+void dqs_setenv(char *name, char *value, int overwrite)
 {
   int i = 0;
   int varlen;

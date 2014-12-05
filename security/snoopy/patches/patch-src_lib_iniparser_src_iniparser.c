$NetBSD: patch-src_lib_iniparser_src_iniparser.c,v 1.1 2014/12/05 14:47:02 imil Exp $

int cast needed to avoid error: array subscript has type 'char'

--- src/lib/iniparser/src/iniparser.c.orig	2014-11-08 16:35:25.000000000 +0000
+++ src/lib/iniparser/src/iniparser.c
@@ -677,7 +677,7 @@ dictionary * iniparser_load(const char *
         }
         /* Get rid of \n and spaces at end of line */
         while ((len>=0) &&
-                ((line[len]=='\n') || (isspace(line[len])))) {
+                ((line[len]=='\n') || (isspace((int)line[len])))) {
             line[len]=0 ;
             len-- ;
         }

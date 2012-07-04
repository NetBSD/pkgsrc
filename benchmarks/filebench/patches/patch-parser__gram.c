$NetBSD: patch-parser__gram.c,v 1.1 2012/07/04 18:47:34 dholland Exp $

Take 'static' off a variable that's used in another file. Fixes broken build.

--- parser_gram.c~	2011-09-06 17:22:21.000000000 +0000
+++ parser_gram.c
@@ -114,7 +114,7 @@ static GetLine *gl;
 /* executable name to execute worker processes later */
 char *execname;
 
-static int dofile = DOFILE_FALSE;
+int dofile = DOFILE_FALSE;
 static FILE *parentscript;
 
 static char *fbbasepath = FILEBENCHDIR;

$NetBSD: patch-include_libiberty.h,v 1.1 2016/09/10 13:59:31 maya Exp $

Don't use PARAMS
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- include/libiberty.h.orig	2011-01-03 20:52:22.000000000 +0000
+++ include/libiberty.h
@@ -85,11 +85,11 @@ extern char **dupargv (char **) ATTRIBUT
 
 /* Expand "@file" arguments in argv.  */
 
-extern void expandargv PARAMS ((int *, char ***));
+extern void expandargv (int *, char ***);
 
 /* Write argv to an @-file, inserting necessary quoting.  */
 
-extern int writeargv PARAMS ((char **, FILE *));
+extern int writeargv (char **, FILE *);
 
 /* Return the last component of a path name.  Note that we can't use a
    prototype here because the parameter is declared inconsistently

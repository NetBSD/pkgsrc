$NetBSD: patch-cracklib_packer.h,v 1.1 2026/06/18 14:27:56 nia Exp $

Fix implicit declarations in various files, including packlib.c and
fascist.c.

--- cracklib/packer.h.orig	1997-12-31 10:26:01.000000000 +0000
+++ cracklib/packer.h
@@ -7,6 +7,8 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 
 #define STRINGSIZE	1024
@@ -52,7 +54,14 @@ extern PWDICT *PWOpen();
 #define PIH_MAGIC 0x70775631
 
 extern PWDICT *PWOpen();
+extern int PutPW(PWDICT *, char *);
+extern int PMatch(register char *, register char *);
+extern int PWClose(PWDICT *);
+extern int32 FindPW(PWDICT *, char *);
+extern char *GetPW(PWDICT *, int32);
 extern char *Mangle();
+extern char *Trim(register char *);
+extern char Chop(register char *string);
 extern char *FascistCheck();
 
 #define CRACK_TOLOWER(a) 	(isupper(a)?tolower(a):(a)) 

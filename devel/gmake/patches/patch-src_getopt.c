$NetBSD: patch-src_getopt.c,v 1.1 2026/05/18 11:49:53 jperkin Exp $

Fix for modern C.

--- src/getopt.c.orig	2023-01-12 00:53:26.000000000 +0000
+++ src/getopt.c
@@ -202,7 +202,7 @@ static char *posixly_correct;
    whose names are inconsistent.  */
 
 #ifndef getenv
-extern char *getenv ();
+extern char *getenv (const char *);
 #endif
 
 static char *

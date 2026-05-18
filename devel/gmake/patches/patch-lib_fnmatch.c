$NetBSD: patch-lib_fnmatch.c,v 1.1 2026/05/18 11:49:53 jperkin Exp $

Fix for modern C.

--- lib/fnmatch.c.orig	2023-02-26 16:04:31.000000000 +0000
+++ lib/fnmatch.c
@@ -121,7 +121,7 @@ USA.  */
    whose names are inconsistent.  */
 
 # if !defined _LIBC && !defined getenv
-extern char *getenv ();
+extern char *getenv (const char *);
 # endif
 
 # ifndef errno

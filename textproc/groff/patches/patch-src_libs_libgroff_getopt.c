$NetBSD: patch-src_libs_libgroff_getopt.c,v 1.1 2026/06/16 11:51:09 nia Exp $

Use the correct, standards-conforming arguments for the local
getenv prototype. This is necessary for C23 and GCC 15 compatibility.
We can't include <stdlib.h> for the real prototype because it
conflicts wit the getopt override.

--- src/libs/libgroff/getopt.c.orig	2023-07-02 16:09:34.000000000 +0000
+++ src/libs/libgroff/getopt.c
@@ -122,7 +122,7 @@ static struct _getopt_data getopt_data;
    whose names are inconsistent.  */
 
 #ifndef getenv
-extern char *getenv ();
+extern char *getenv (const char *);
 #endif
 
 #endif /* not __GNU_LIBRARY__ */

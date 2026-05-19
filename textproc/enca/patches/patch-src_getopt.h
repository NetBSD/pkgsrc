$NetBSD: patch-src_getopt.h,v 1.1 2026/05/19 09:34:17 jperkin Exp $

Fix for modern C.

--- src/getopt.h.orig	2026-05-19 09:32:49.895189054 +0000
+++ src/getopt.h
@@ -144,7 +144,7 @@ struct option
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int __argc, char *const *__argv, const char *__shortopts);
 # else /* not __GNU_LIBRARY__ */
-extern int getopt ();
+extern int getopt (int,  char * const*, const char *);
 # endif /* __GNU_LIBRARY__ */
 
 # ifndef __need_getopt

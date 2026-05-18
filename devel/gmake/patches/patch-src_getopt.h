$NetBSD: patch-src_getopt.h,v 1.1 2026/05/18 11:49:53 jperkin Exp $

Fix for modern C.

--- src/getopt.h.orig	2023-01-01 15:06:01.000000000 +0000
+++ src/getopt.h
@@ -102,7 +102,7 @@ struct option
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
-extern int getopt ();
+extern int getopt (int, char *const *, const char *);
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);

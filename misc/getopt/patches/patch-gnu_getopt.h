$NetBSD: patch-gnu_getopt.h,v 1.1 2026/05/19 07:57:55 jperkin Exp $

Fix for modern C.

--- gnu/getopt.h.orig	2026-05-19 07:33:46.925838527 +0000
+++ gnu/getopt.h
@@ -103,7 +103,7 @@ struct option
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
-extern int getopt ();
+extern int getopt (int, char *const *, const char *);
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);

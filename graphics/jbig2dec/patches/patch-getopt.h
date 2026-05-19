$NetBSD: patch-getopt.h,v 1.1 2026/05/19 09:25:21 jperkin Exp $

Fix for modern C.

--- getopt.h.orig	2026-05-19 09:23:59.193722989 +0000
+++ getopt.h
@@ -143,7 +143,7 @@ struct option {
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt(int __argc, char *const *__argv, const char *__shortopts);
 # else                          /* not __GNU_LIBRARY__ */
-extern int getopt();
+extern int getopt(int, char *const *, const char *);
 # endif                         /* __GNU_LIBRARY__ */
 
 # ifndef __need_getopt

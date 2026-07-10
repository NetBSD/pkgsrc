$NetBSD: patch-Wnn_include_getopt.h,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Fix prototype declaration for getopt()

--- Wnn/include/getopt.h.orig	2003-05-11 18:38:05.000000000 +0000
+++ Wnn/include/getopt.h
@@ -112,7 +112,7 @@ struct option
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
 # if !defined (HAVE_DECL_GETOPT)
-extern int getopt ();
+extern int getopt (int argc, char *const *argv, const char *shortopts);
 # endif
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,

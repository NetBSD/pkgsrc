$NetBSD: patch-examples_getopt_getopt.h,v 1.1 2022/04/12 20:10:46 tnn Exp $

don't conflict with system's getopt prototype

--- examples/getopt/getopt.h.orig	2021-12-14 18:37:20.000000000 +0000
+++ examples/getopt/getopt.h
@@ -14,6 +14,6 @@ extern int   optind;
 extern int   optopt;
 extern char* optarg;
 
-int getopt(int argc, char **argv, char *opts);
+int getopt(int argc, char *const *argv, const char *opts);
 
 #endif /* _GETOPT_H_ */

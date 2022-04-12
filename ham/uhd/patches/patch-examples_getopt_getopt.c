$NetBSD: patch-examples_getopt_getopt.c,v 1.1 2022/04/12 20:10:46 tnn Exp $

don't conflict with system's getopt prototype

--- examples/getopt/getopt.c.orig	2021-12-14 18:37:20.000000000 +0000
+++ examples/getopt/getopt.c
@@ -23,7 +23,7 @@ int optopt;
 char *optarg;
 
 int
-getopt(int argc, char **argv, char *opts)
+getopt(int argc, char *const *argv, const char *opts)
 {
     static int sp;
     int c;

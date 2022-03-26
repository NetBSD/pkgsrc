$NetBSD: patch-cstool_getopt.h,v 1.1 2022/03/26 19:25:51 tnn Exp $

Use the standard optarg prototype.

--- cstool/getopt.h.orig	2020-05-08 10:03:30.000000000 +0000
+++ cstool/getopt.h
@@ -6,7 +6,7 @@ int opterr = 1, /* if error message shou
 optind = 1, /* index into parent argv vector */
 optopt, /* character checked for validity */
 optreset; /* reset getopt */
-const char *optarg; /* argument associated with option */
+extern char *optarg; /* argument associated with option */
 
 #define BADCH (int)'?'
 #define BADARG (int)':'

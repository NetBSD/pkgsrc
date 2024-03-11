$NetBSD: patch-cstool_getopt.c,v 1.1 2024/03/11 09:21:01 jperkin Exp $

Handle illumos getopt.

--- cstool/getopt.c.orig	2024-03-11 09:16:44.155866444 +0000
+++ cstool/getopt.c
@@ -7,7 +7,11 @@ int opterr = 1, /* if error message shou
 optind = 1, /* index into parent argv vector */
 optopt, /* character checked for validity */
 optreset; /* reset getopt */
+#ifdef __illumos__
+char *optarg;
+#else
 const char *optarg; /* argument associated with option */
+#endif
 
 #define BADCH (int)'?'
 #define BADARG (int)':'

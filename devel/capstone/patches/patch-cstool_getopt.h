$NetBSD: patch-cstool_getopt.h,v 1.3 2024/03/11 09:21:01 jperkin Exp $

Handle illumos getopt.

--- cstool/getopt.h.orig	2024-03-11 09:17:17.512916711 +0000
+++ cstool/getopt.h
@@ -7,7 +7,11 @@ optind, /* index into parent argv vector
 optopt, /* character checked for validity */
 optreset; /* reset getopt */
 
+#ifdef __illumos__
+extern char *optarg;
+#else
 extern const char *optarg; /* argument associated with option */
+#endif
 
 int getopt (int nargc, char *const nargv[], const char *ostr);
 

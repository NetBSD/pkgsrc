$NetBSD: patch-examples_heif__info.cc,v 1.1 2020/09/03 19:07:19 otis Exp $

Excplicitly cast types to make ISO C++ happy

--- examples/heif_info.cc.orig	2020-08-13 16:57:45.000000000 +0000
+++ examples/heif_info.cc
@@ -38,6 +38,10 @@
 #define STDOUT_FILENO 1
 #endif
 
+#if defined(sun) || defined(__sun)
+#include <alloca.h>
+#endif
+
 #include <libheif/heif.h>
 
 #include <fstream>
@@ -65,8 +69,8 @@ info -d // dump
 static struct option long_options[] = {
     //{"write-raw", required_argument, 0, 'w' },
     //{"output",    required_argument, 0, 'o' },
-    {"dump-boxes", no_argument, 0, 'd'},
-    {"help",       no_argument, 0, 'h'},
+    {(char * const)"dump-boxes", no_argument, 0, 'd'},
+    {(char * const)"help",       no_argument, 0, 'h'},
     {0, 0,                      0, 0}
 };
 

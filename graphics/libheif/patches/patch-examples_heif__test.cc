$NetBSD: patch-examples_heif__test.cc,v 1.1 2020/09/03 19:07:19 otis Exp $

Excplicitly cast types to make ISO C++ happy

--- examples/heif_test.cc.orig	2020-08-13 16:57:45.000000000 +0000
+++ examples/heif_test.cc
@@ -50,8 +50,8 @@
 static struct option long_options[] = {
     //{"write-raw", required_argument, 0, 'w' },
     //{"output",    required_argument, 0, 'o' },
-    {"decode-img", required_argument, 0, 'd'},
-    {"metadata",   required_argument, 0, 'm'},
+    {(char * const)"decode-img", required_argument, 0, 'd'},
+    {(char * const)"metadata",   required_argument, 0, 'm'},
     {0, 0,                            0, 0}
 };
 

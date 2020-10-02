$NetBSD: patch-examples_heif__info.cc,v 1.3 2020/10/02 17:09:35 otis Exp $

Help the compiler find the correct prototype for alloca()

--- examples/heif_info.cc.orig	2020-09-22 10:09:51.000000000 +0000
+++ examples/heif_info.cc
@@ -34,6 +34,10 @@
 
 #include <unistd.h>
 
+#if defined(__sun) || defined(sun)
+#include <alloca.h>
+#endif
+
 #else
 #define STDOUT_FILENO 1
 #endif

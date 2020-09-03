$NetBSD: patch-examples_heif__convert.cc,v 1.1 2020/09/03 19:07:19 otis Exp $

Include alloca.h on SunOS

--- examples/heif_convert.cc.orig	2020-08-13 16:57:45.000000000 +0000
+++ examples/heif_convert.cc
@@ -35,6 +35,10 @@
 
 #endif
 
+#if defined(sun) || defined(__sun)
+#include <alloca.h>
+#endif
+
 #include <fstream>
 #include <iostream>
 #include <sstream>

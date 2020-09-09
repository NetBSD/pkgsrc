$NetBSD: patch-modules_core_src_rand.cpp,v 1.1 2020/09/09 11:50:50 nia Exp $

Include arm_neon.h before attempting to use intrinsics.

This is seemingly fixed in newer releases.

--- modules/core/src/rand.cpp.orig	2019-12-19 15:16:47.000000000 +0000
+++ modules/core/src/rand.cpp
@@ -60,6 +60,10 @@
     #include "emmintrin.h"
 #endif
 
+#if defined __ARM_NEON && defined __aarch64__
+    #include "arm_neon.h"
+#endif
+
 namespace cv
 {
 

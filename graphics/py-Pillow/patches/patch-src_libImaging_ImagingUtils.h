$NetBSD: patch-src_libImaging_ImagingUtils.h,v 1.2 2018/04/03 09:24:20 adam Exp $

Fix building with GCC 4.x; https://github.com/python-pillow/Pillow/issues/2956

--- src/libImaging/ImagingUtils.h.orig	2018-01-01 21:04:32.000000000 +0000
+++ src/libImaging/ImagingUtils.h
@@ -37,7 +37,7 @@
     ! defined(__clang__) && defined(GCC_VERSION) && (GCC_VERSION < 40900)
 static float __attribute__((always_inline)) inline _i2f(int v) {
     float x;
-    __asm__("xorps %0, %0; cvtsi2ss %1, %0" : "=X"(x) : "r"(v) );
+    __asm__("xorps %0, %0; cvtsi2ss %1, %0" : "=x"(x) : "r"(v) );
     return x;
 }
 #else

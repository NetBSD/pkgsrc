$NetBSD: patch-src_libImaging_ImagingUtils.h,v 1.1 2018/01/12 19:50:52 adam Exp $

Disable the work around; it does not really work.

--- src/libImaging/ImagingUtils.h.orig	2018-01-12 19:46:54.000000000 +0000
+++ src/libImaging/ImagingUtils.h
@@ -30,16 +30,4 @@
     (MULDIV255(in1, (255 - mask), tmp1) + in2)
 
 
-/* This is to work around a bug in GCC prior 4.9 in 64 bit mode.
-   GCC generates code with partial dependency which is 3 times slower.
-   See: http://stackoverflow.com/a/26588074/253146 */
-#if defined(__x86_64__) && defined(__SSE__) &&  ! defined(__NO_INLINE__) && \
-    ! defined(__clang__) && defined(GCC_VERSION) && (GCC_VERSION < 40900)
-static float __attribute__((always_inline)) inline _i2f(int v) {
-    float x;
-    __asm__("xorps %0, %0; cvtsi2ss %1, %0" : "=X"(x) : "r"(v) );
-    return x;
-}
-#else
 static float inline _i2f(int v) { return (float) v; }
-#endif

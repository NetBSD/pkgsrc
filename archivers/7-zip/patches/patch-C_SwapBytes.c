$NetBSD: patch-C_SwapBytes.c,v 1.1 2023/08/02 16:00:49 nia Exp $

Fix compiling with GCC 7 and earlier versions.

--- C/SwapBytes.c.orig	2023-08-02 08:09:50.974230468 +0000
+++ C/SwapBytes.c
@@ -22,7 +22,12 @@ typedef UInt32 CSwapUInt32;
   // #if defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 1900)
   #if defined(__clang__) && (__clang_major__ >= 4) \
       || defined(Z7_GCC_VERSION) && (Z7_GCC_VERSION >= 40701)
-      #define k_SwapBytes_Mode_MAX  k_SwapBytes_Mode_AVX2
+      // mm256_set_m128i is not present in GCC 7
+      #if !defined(__clang__) && __GNUC__ >= 8
+          #define k_SwapBytes_Mode_MAX  k_SwapBytes_Mode_AVX2
+      #else
+          #define k_SwapBytes_Mode_MAX  k_SwapBytes_Mode_SSE2
+      #endif
       #define SWAP_ATTRIB_SSE2  __attribute__((__target__("sse2")))
       #define SWAP_ATTRIB_SSSE3 __attribute__((__target__("ssse3")))
       #define SWAP_ATTRIB_AVX2  __attribute__((__target__("avx2")))

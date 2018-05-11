$NetBSD: patch-random_jitterentropy-base.c,v 1.1 2018/05/11 19:20:11 kamil Exp $

Port to Clang.

--- random/jitterentropy-base.c.orig	2017-11-23 18:16:58.000000000 +0000
+++ random/jitterentropy-base.c
@@ -50,13 +50,18 @@
  */
 
 #undef _FORTIFY_SOURCE
+
+#ifdef __clang__
+#pragma clang optimize off
+#else
 #pragma GCC optimize ("O0")
+#endif
 
 #include "jitterentropy.h"
 
 #ifndef CONFIG_CRYPTO_CPU_JITTERENTROPY_STAT
  /* only check optimization in a compilation for real work */
- #ifdef __OPTIMIZE__
+ #if defined(__OPTIMIZE__) && !defined(__clang__)
   #error "The CPU Jitter random number generator must not be compiled with optimizations. See documentation. Use the compiler switch -O0 for compiling jitterentropy-base.c."
  #endif
 #endif

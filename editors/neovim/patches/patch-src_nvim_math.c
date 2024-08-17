$NetBSD: patch-src_nvim_math.c,v 1.1 2024/08/17 15:43:33 bsiegert Exp $

- avoid conflict with NetBSD's popcount(3)

--- src/nvim/math.c.orig	2024-05-27 21:57:43.595089547 +0000
+++ src/nvim/math.c
@@ -78,13 +78,14 @@ int xctz(uint64_t x)
 }

 /// Count number of set bits in bit field.
-int popcount(uint64_t x)
+unsigned xpopcount(uint64_t x)
 {
-  // Use compiler builtin if possible.
-#if defined(__clang__) || defined(__GNUC__)
-  return __builtin_popcountll(x);
+#if defined(__NetBSD__)
+  return popcount64(x);
+#elif defined(__clang__) || defined(__GNUC__)
+  return (unsigned)__builtin_popcountll(x);
 #else
-  int count = 0;
+  unsigned count = 0;
   for (; x != 0; x >>= 1) {
     if (x & 1) {
       count++;

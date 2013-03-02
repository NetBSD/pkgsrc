$NetBSD: patch-.._gcc-4.0.3_gcc_toplev.h,v 1.1 2013/03/02 18:05:46 joerg Exp $

--- ../gcc-4.0.3/gcc/toplev.h.orig	2013-03-01 10:43:23.000000000 +0000
+++ ../gcc-4.0.3/gcc/toplev.h
@@ -180,13 +180,13 @@ extern int floor_log2                  (
 #  define CTZ_HWI __builtin_ctz
 # endif
 
-extern inline int
+extern __attribute__((__gnu_inline__)) inline int
 floor_log2 (unsigned HOST_WIDE_INT x)
 {
   return x ? HOST_BITS_PER_WIDE_INT - 1 - (int) CLZ_HWI (x) : -1;
 }
 
-extern inline int
+extern __attribute__((__gnu_inline__)) inline int
 exact_log2 (unsigned HOST_WIDE_INT x)
 {
   return x == (x & -x) && x ? (int) CTZ_HWI (x) : -1;

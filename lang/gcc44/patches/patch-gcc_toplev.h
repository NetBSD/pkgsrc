$NetBSD: patch-gcc_toplev.h,v 1.1 2013/03/02 18:05:01 joerg Exp $

--- gcc/toplev.h.orig	2009-02-20 15:20:38.000000000 +0000
+++ gcc/toplev.h
@@ -186,13 +186,13 @@ extern int floor_log2                  (
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

$NetBSD: patch-gcc_toplev.h,v 1.1 2014/09/10 12:13:06 joerg Exp $

--- gcc/toplev.h.orig	2013-06-13 21:33:10.000000000 +0000
+++ gcc/toplev.h
@@ -171,13 +171,13 @@ extern int floor_log2                  (
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

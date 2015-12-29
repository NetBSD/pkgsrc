$NetBSD: patch-gcc_toplev.h,v 1.2 2015/12/29 23:34:46 dholland Exp $

Patch up gcc inline mess.

--- ../gcc-4.1.2/gcc/toplev.h.orig	2005-09-09 00:47:05.000000000 +0000
+++ ../gcc-4.1.2/gcc/toplev.h
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

$NetBSD: patch-gcc_toplev.h,v 1.1 2012/11/16 00:38:21 joerg Exp $

--- gcc/toplev.h.orig	2012-11-14 17:06:44.000000000 +0000
+++ gcc/toplev.h
@@ -185,18 +185,6 @@ extern int floor_log2                  (
 #  define CLZ_HWI __builtin_clz
 #  define CTZ_HWI __builtin_ctz
 # endif
-
-extern inline int
-floor_log2 (unsigned HOST_WIDE_INT x)
-{
-  return x ? HOST_BITS_PER_WIDE_INT - 1 - (int) CLZ_HWI (x) : -1;
-}
-
-extern inline int
-exact_log2 (unsigned HOST_WIDE_INT x)
-{
-  return x == (x & -x) && x ? (int) CTZ_HWI (x) : -1;
-}
 #endif /* GCC_VERSION >= 3004 */
 
 /* Functions used to get and set GCC's notion of in what directory

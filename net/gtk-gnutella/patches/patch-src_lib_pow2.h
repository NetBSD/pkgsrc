$NetBSD: patch-src_lib_pow2.h,v 1.1 2017/02/26 12:58:28 adam Exp $

Don't define popcount() if it exists in system.

--- src/lib/pow2.h.orig	2017-02-26 12:17:53.469638084 +0000
+++ src/lib/pow2.h
@@ -66,6 +66,7 @@ is_pow2(uint32 value)
  *
  * @return number of 1 bits in a 32-bit integer.
  */
+#ifndef HAS_POPCOUNT
 static inline ALWAYS_INLINE G_CONST int
 popcount(uint32 x)
 #ifdef HAS_BUILTIN_POPCOUNT
@@ -84,6 +85,7 @@ popcount(uint32 x)
 	return ((x + (x >> 4) & 0xf0f0f0f) * 0x1010101) >> 24;
 }
 #endif	/* HAS_BUILTIN_POPCOUNT */
+#endif	/* HAS_POPCOUNT */
 
 /**
  * Count trailing zeroes in a 32-bit integer, -1 for zero.

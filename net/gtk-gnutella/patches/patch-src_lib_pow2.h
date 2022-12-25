$NetBSD: patch-src_lib_pow2.h,v 1.3 2022/12/25 18:03:42 wiz Exp $

Don't define popcount() if it exists in system.
https://github.com/gtk-gnutella/gtk-gnutella/pull/34

--- src/lib/pow2.h.orig	2022-02-25 16:06:22.000000000 +0000
+++ src/lib/pow2.h
@@ -67,6 +67,7 @@ is_pow2(uint32 value)
  *
  * @return number of 1 bits in a 32-bit integer.
  */
+#ifndef HAS_POPCOUNT
 static inline ALWAYS_INLINE G_CONST int
 popcount(uint32 x)
 #ifdef HAS_BUILTIN_POPCOUNT
@@ -85,6 +86,7 @@ popcount(uint32 x)
 	return (((x + (x >> 4)) & 0xf0f0f0f) * 0x1010101) >> 24;
 }
 #endif	/* HAS_BUILTIN_POPCOUNT */
+#endif	/* HAS_POPCOUNT */
 
 /**
  * Count trailing zeroes in a 32-bit integer, -1 for zero.

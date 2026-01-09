$NetBSD: patch-cipher_aria.c,v 1.2 2026/01/09 19:26:57 nia Exp $

* Do not conflict with NetBSD's bswap(3).

--- cipher/aria.c.orig	2024-03-28 10:07:27.000000000 +0000
+++ cipher/aria.c
@@ -641,11 +641,15 @@ u32 rotr32(u32 v, u32 r)
   return ror(v, r);
 }
 
+#ifdef __NetBSD__
+#include <sys/bswap.h>
+#else
 static ALWAYS_INLINE
 u32 bswap32(u32 v)
 {
   return _gcry_bswap32(v);
 }
+#endif
 
 static ALWAYS_INLINE u32
 get_u8(u32 x, u32 y)

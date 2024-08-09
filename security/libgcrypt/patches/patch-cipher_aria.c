$NetBSD: patch-cipher_aria.c,v 1.1 2024/08/09 03:51:27 ryoon Exp $

* Do not conflict with NetBSD's bswap(3).

--- cipher/aria.c.orig	2024-08-02 04:47:06.896383457 +0000
+++ cipher/aria.c
@@ -641,11 +641,13 @@ u32 rotr32(u32 v, u32 r)
   return ror(v, r);
 }
 
+#if !defined(__NetBSD__)
 static ALWAYS_INLINE
 u32 bswap32(u32 v)
 {
   return _gcry_bswap32(v);
 }
+#endif
 
 static ALWAYS_INLINE u32
 get_u8(u32 x, u32 y)

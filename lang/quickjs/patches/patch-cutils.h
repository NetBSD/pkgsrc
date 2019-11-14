$NetBSD: patch-cutils.h,v 1.1 2019/11/14 21:20:04 rillig Exp $

Portability patch for NetBSD.

--- cutils.h.orig	2019-10-27 10:55:35.000000000 +0000
+++ cutils.h
@@ -207,17 +207,22 @@ static inline void put_u8(uint8_t *tab, 
     *tab = val;
 }
 
+#ifndef bswap16
 static inline uint16_t bswap16(uint16_t x)
 {
     return (x >> 8) | (x << 8);
 }
+#endif
 
+#ifndef bswap32
 static inline uint32_t bswap32(uint32_t v)
 {
     return ((v & 0xff000000) >> 24) | ((v & 0x00ff0000) >>  8) |
         ((v & 0x0000ff00) <<  8) | ((v & 0x000000ff) << 24);
 }
+#endif
 
+#ifndef bswap64
 static inline uint64_t bswap64(uint64_t v)
 {
     return ((v & ((uint64_t)0xff << (7 * 8))) >> (7 * 8)) | 
@@ -229,6 +234,7 @@ static inline uint64_t bswap64(uint64_t 
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) | 
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);

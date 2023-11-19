$NetBSD: patch-cutils.h,v 1.1 2023/11/19 13:00:26 bacon Exp $

Remove unused functions. These cause a compiler error on NetBSD
but don't have an issue on Darwin or Linux.

--- cutils.h.orig	2023-03-09 11:57:59.000000000 +0000
+++ cutils.h
@@ -394,6 +394,7 @@ static inline void put_u8(uint8_t *tab, 
     *tab = val;
 }
 
+#ifndef __NetBSD__
 static inline uint16_t bswap16(uint16_t x)
 {
     return (x >> 8) | (x << 8);
@@ -416,6 +417,7 @@ static inline uint64_t bswap64(uint64_t 
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) |
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);

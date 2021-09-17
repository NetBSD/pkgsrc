$NetBSD: patch-src_quickjs_cutils.h,v 1.1 2021/09/17 00:10:21 nia Exp $

Avoid colliding with NetBSD libc functions.

--- src/quickjs/cutils.h.orig	2020-09-10 16:38:49.000000000 +0000
+++ src/quickjs/cutils.h
@@ -266,6 +266,9 @@ static inline void put_u8(uint8_t *tab, 
     *tab = val;
 }
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 static inline uint16_t bswap16(uint16_t x)
 {
     return (x >> 8) | (x << 8);
@@ -288,6 +291,7 @@ static inline uint64_t bswap64(uint64_t 
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) | 
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);

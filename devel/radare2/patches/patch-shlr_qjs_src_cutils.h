$NetBSD: patch-shlr_qjs_src_cutils.h,v 1.1 2022/12/28 04:36:55 khorben Exp $

* Build fix for NetBSD

--- shlr/qjs/src/cutils.h.orig	2022-12-28 04:15:25.740716462 +0000
+++ shlr/qjs/src/cutils.h
@@ -295,17 +295,22 @@ static inline void put_u8(uint8_t *tab, 
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
@@ -317,6 +322,7 @@ static inline uint64_t bswap64(uint64_t 
         ((v & ((uint64_t)0xff << (1 * 8))) << (5 * 8)) | 
         ((v & ((uint64_t)0xff << (0 * 8))) << (7 * 8));
 }
+#endif
 
 /* XXX: should take an extra argument to pass slack information to the caller */
 typedef void *DynBufReallocFunc(void *opaque, void *ptr, size_t size);

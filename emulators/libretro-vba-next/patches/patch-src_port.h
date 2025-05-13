$NetBSD: patch-src_port.h,v 1.1 2025/05/13 13:39:52 nia Exp $

Fix the broken byte swapping code for non-PowerPC big endian platforms.

--- src/port.h.orig	2020-01-06 22:55:53.000000000 +0000
+++ src/port.h
@@ -75,11 +75,18 @@
 #define READ32LE( base) _byteswap_ulong(*((u32 *)(base)))
 #define WRITE16LE(base, value) *((u16 *)(base)) = _byteswap_ushort((value))
 #define WRITE32LE(base, value) *((u32 *)(base)) = _byteswap_ulong((value))
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define READ16LE(x) BSWAP_16(*((u16 *)(x)))
+#define READ32LE(x) BSWAP_32(*((u32 *)(x)))
+#define WRITE16LE(x,v) *((u16 *)(x)) = BSWAP_16((v))
+#define WRITE32LE(x,v) *((u32 *)(x)) = BSWAP_32((v))
 #else
-#define READ16LE(x) (*((u16 *)(x))<<8)|(*((u16 *)(x))>>8);
-#define READ32LE(x) (*((u32 *)(x))<<24)|((*((u32 *)(x))<<8)&0xff0000)|((((*((u32 *)(x))(x)>>8)&0xff00)|(*((u32 *)(x))>>24);
-#define WRITE16LE(x,v) *((u16 *)(x)) = (*((u16 *)(v))<<8)|(*((u16 *)(v))>>8);
-#define WRITE32LE(x,v) *((u32 *)(x)) = ((v)<<24)|(((v)<<8)&0xff0000)|(((v)>>8)&0xff00)|((v)>>24);
+#include <sys/endian.h>
+#define READ16LE(x) le16toh(*((u16 *)(x)))
+#define READ32LE(x) le32toh(*((u32 *)(x)))
+#define WRITE16LE(x,v) *((u16 *)(x)) = htole16((v))
+#define WRITE32LE(x,v) *((u32 *)(x)) = htole32((v))
 #endif
 #else
 #define READ16LE(x) *((u16 *)(x))

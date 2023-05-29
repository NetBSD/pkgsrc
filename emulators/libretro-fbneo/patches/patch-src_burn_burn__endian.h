$NetBSD: patch-src_burn_burn__endian.h,v 1.1 2023/05/29 14:33:14 nia Exp $

More than games consoles are big endian.

--- src/burn/burn_endian.h.orig	2023-05-24 08:09:39.000000000 +0000
+++ src/burn/burn_endian.h
@@ -41,6 +41,13 @@ typedef union {
 #define BURN_ENDIAN_SWAP_INT16(x)				({uint16_t tt; __sthbrx(&tt, x); tt;})
 #define BURN_ENDIAN_SWAP_INT32(x)				({uint32_t tt; __stwbrx(&tt, x); tt;})
 #define NO_64BIT_BYTESWAP
+// NetBSD
+#elif defined(__NetBSD__)
+#include <machine/endian.h>
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				(bswap16(x))
+#define BURN_ENDIAN_SWAP_INT32(x)				(bswap32(x))
+#define BURN_ENDIAN_SWAP_INT64(x)				(bswap64(x))
 // GC/Wii/WiiU
 //#elif defined(HW_RVL)
 //#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)

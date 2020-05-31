$NetBSD: patch-src_burner_libretro_burn__endian.h,v 1.1 2020/05/31 12:28:12 nia Exp $

More than games consoles are big endian.

--- src/burner/libretro/burn_endian.h.orig	2020-05-30 15:55:11.000000000 +0000
+++ src/burner/libretro/burn_endian.h
@@ -1,7 +1,7 @@
 #ifndef _FBNEO_ENDIAN_H
 #define _FBNEO_ENDIAN_H
 
-#ifndef _XBOX
+#if !defined(_XBOX) && !defined(__NetBSD__)
 #define NO_64BIT_BYTESWAP
 #endif
 
@@ -46,6 +46,13 @@ typedef union {
 #define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
 #define BURN_ENDIAN_SWAP_INT16(x)				({uint16_t tt; __sthbrx(&tt, 0, x); tt;})
 #define BURN_ENDIAN_SWAP_INT32(x)				({uint32_t tt; __stwbrx(&tt, 0, x); tt;})
+/* NetBSD */
+#elif defined(__NetBSD__)
+#include <machine/endian.h>
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				(bswap16(x))
+#define BURN_ENDIAN_SWAP_INT32(x)				(bswap32(x))
+#define BURN_ENDIAN_SWAP_INT64(x)				(bswap64(x))
 #else
 #define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
 #define BURN_ENDIAN_SWAP_INT16(x)				((((x) << 8) & 0xff00) | (((x) >> 8) & 0x00ff))

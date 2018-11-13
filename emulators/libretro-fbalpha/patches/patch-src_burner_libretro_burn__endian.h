$NetBSD: patch-src_burner_libretro_burn__endian.h,v 1.1 2018/11/13 17:16:25 nia Exp $

More than games consoles are big endian.

--- src/burner/libretro/burn_endian.h.orig	2018-11-13 16:00:03.905824261 +0000
+++ src/burner/libretro/burn_endian.h
@@ -1,7 +1,7 @@
 #ifndef _FBA_ENDIAN_H
 #define _FBA_ENDIAN_H
 
-#ifndef _XBOX
+#if !defined(_XBOX) && !defined(__NetBSD__)
 #define NO_64BIT_BYTESWAP
 #endif
 
@@ -49,6 +49,17 @@ typedef union {
 /* Not sure the asm stuff is working properly, so trying something else for debugging (may be slower) */
 //#define BURN_ENDIAN_SWAP_INT16(x)				(((x) >> 8) | (((x) & 0xFF) << 8))
 //#define BURN_ENDIAN_SWAP_INT32(x)				(((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | (((x) & 0xFF) << 24))
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <machine/bswap.h>
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				(bswap16(x))
+#define BURN_ENDIAN_SWAP_INT32(x)				(bswap32(x))
+#define BURN_ENDIAN_SWAP_INT64(x)				(bswap64(x))
+#else
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				((((x) << 8) & 0xff00) | (((x) >> 8) & 0x00ff))
+#define BURN_ENDIAN_SWAP_INT32(x)				((((x) << 24) & 0xff000000) | (((x) << 8) & 0x00ff0000) | (((x) >> 8) & 0x0000ff00) | (((x) >> 24) & 0x000000ff))
 #endif
 
 #ifdef NO_64BIT_BYTESWAP

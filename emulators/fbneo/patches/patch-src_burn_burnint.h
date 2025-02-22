$NetBSD: patch-src_burn_burnint.h,v 1.2 2025/02/22 19:37:36 rillig Exp $

Teach fbneo about endian on NetBSD.

--- src/burn/burnint.h.orig	2021-05-01 20:32:23.000000000 +0000
+++ src/burn/burnint.h
@@ -30,8 +30,8 @@ typedef union
 #define BURN_ENDIAN_SWAP_INT64(x)				x
 #else
 
-// Xbox 360 has byteswap 64-bit intrinsic
-#ifndef _XBOX
+// Xbox 360 and NetBSD have byteswap 64-bit intrinsic
+#if !definded(_XBOX) && !defined(__NetBSD__)
 #define NO_64BIT_BYTESWAP
 #endif
 
@@ -80,6 +80,13 @@ typedef union {
 #define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
 #define BURN_ENDIAN_SWAP_INT16(x)				({uint16_t tt; __sthbrx(&tt, 0, x); tt;})
 #define BURN_ENDIAN_SWAP_INT32(x)				({uint32_t tt; __stwbrx(&tt, 0, x); tt;})
+// NetBSD
+#elif defined(__NetBSD__)
+#include <machine/endian.h>
+#define BURN_ENDIAN_SWAP_INT8(x)				(x^1)
+#define BURN_ENDIAN_SWAP_INT16(x)				(bswap16(x))
+#define BURN_ENDIAN_SWAP_INT32(x)				(bswap32(x))
+#define BURN_ENDIAN_SWAP_INT64(x)				(bswap64(x))
 // gcc/clang
 #elif defined(__GNUC__)
 #define BURN_ENDIAN_SWAP_INT8(x)				(x^1)

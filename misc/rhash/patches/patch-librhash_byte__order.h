$NetBSD: patch-librhash_byte__order.h,v 1.5 2017/08/15 08:37:47 adam Exp $

Recognize BSDish endian macros.

--- librhash/byte_order.h.orig	2017-08-14 00:56:22.000000000 +0000
+++ librhash/byte_order.h
@@ -10,6 +10,8 @@
 
 #ifdef __GLIBC__
 # include <endian.h>
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
+# include <sys/endian.h>
 #endif
 
 #ifdef __cplusplus
@@ -38,6 +40,7 @@ extern "C" {
 /* detect CPU endianness */
 #if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && \
 		__BYTE_ORDER == __LITTLE_ENDIAN) || \
+	(defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN) && _BYTE_ORDER == _LITTLE_ENDIAN + 0) || \
 	(defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && \
 		__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || \
 	defined(CPU_IA32) || defined(CPU_X64) || \
@@ -48,6 +51,7 @@ extern "C" {
 # define IS_LITTLE_ENDIAN 1
 #elif (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && \
 		__BYTE_ORDER == __BIG_ENDIAN) || \
+	(defined(_BYTE_ORDER) && defined(_BIG_ENDIAN) && _BYTE_ORDER == _BIG_ENDIAN + 0) || \
 	(defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && \
 		__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || \
 	defined(__sparc) || defined(__sparc__) || defined(sparc) || \

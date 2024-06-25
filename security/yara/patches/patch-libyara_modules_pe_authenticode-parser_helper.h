$NetBSD: patch-libyara_modules_pe_authenticode-parser_helper.h,v 1.1 2024/06/25 05:55:31 adam Exp $

NetBSD already has bswap16/32.

--- libyara/modules/pe/authenticode-parser/helper.h.orig	2024-06-25 05:25:44.694385833 +0000
+++ libyara/modules/pe/authenticode-parser/helper.h
@@ -38,8 +38,12 @@ extern "C" {
 #endif
 
 /* Endianity related functions for PE reading */
+#if defined(__NetBSD__)
+#include <sys/endian.h>
+#else
 uint16_t bswap16(uint16_t d);
 uint32_t bswap32(uint32_t d);
+#endif
 
 #if defined(WORDS_BIGENDIAN)
 #define letoh16(x) bswap16(x)

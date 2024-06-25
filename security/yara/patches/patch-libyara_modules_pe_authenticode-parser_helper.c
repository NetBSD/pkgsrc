$NetBSD: patch-libyara_modules_pe_authenticode-parser_helper.c,v 1.1 2024/06/25 05:55:31 adam Exp $

NetBSD already has bswap16/32.

--- libyara/modules/pe/authenticode-parser/helper.c.orig	2024-06-25 05:52:44.286197248 +0000
+++ libyara/modules/pe/authenticode-parser/helper.c
@@ -28,6 +28,7 @@ SOFTWARE.
 #include <stdlib.h>
 #include <string.h>
 
+#if !defined(__NetBSD__)
 uint16_t bswap16(uint16_t d)
 {
     return (d << 8) | (d >> 8);
@@ -38,6 +39,7 @@ uint32_t bswap32(uint32_t d)
     return (((d)&0xff000000) >> 24) | (((d)&0x00ff0000) >> 8) | (((d)&0x0000ff00) << 8) |
            (((d)&0x000000ff) << 24);
 }
+#endif
 
 int calculate_digest(const EVP_MD* md, const uint8_t* data, size_t len, uint8_t* digest)
 {

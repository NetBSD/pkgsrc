$NetBSD: patch-src_pk_asn1_der_utf8_der__decode__utf8__string.c,v 1.1 2024/07/27 06:06:46 wiz Exp $

Fix CVE-2019-17362 using
https://github.com/libtom/libtomcrypt/commit/25c26a3b7a9ad8192ccc923e15cf62bf0108ef94

--- src/pk/asn1/der/utf8/der_decode_utf8_string.c.orig	2024-07-27 06:03:31.719515951 +0000
+++ src/pk/asn1/der/utf8/der_decode_utf8_string.c
@@ -76,7 +76,7 @@ int der_decode_utf8_string(const unsigne
       /* count number of bytes */
       for (z = 0; (tmp & 0x80) && (z <= 4); z++, tmp = (tmp << 1) & 0xFF);
 
-      if (z > 4 || (x + (z - 1) > inlen)) {
+      if (z == 1 || z > 4 || (x + (z - 1) > inlen)) {
          return CRYPT_INVALID_PACKET;
       }
 

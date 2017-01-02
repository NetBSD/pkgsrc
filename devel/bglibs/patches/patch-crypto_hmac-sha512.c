$NetBSD: patch-crypto_hmac-sha512.c,v 1.2 2017/01/02 02:18:30 schmonz Exp $

Rename hmac to bghmac.

--- crypto/hmac-sha512.c.orig	2016-12-18 09:59:00.448666869 +0000
+++ crypto/hmac-sha512.c
@@ -46,7 +46,7 @@ static void test_hmac(const char* key, c
   const str data_str = { (char*)data, strlen(data), 0 };
   unsigned char digest[SHA512_DIGEST_LENGTH];
   unsigned i;
-  hmac(&hmac_sha512, &key_str, &data_str, digest);
+  bghmac(&hmac_sha512, &key_str, &data_str, digest);
   for (i = 0; i < sizeof digest; ++i)
     obuf_putxw(&outbuf, digest[i], 2, '0');
   obuf_endl(&outbuf);

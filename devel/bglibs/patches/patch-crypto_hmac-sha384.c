$NetBSD: patch-crypto_hmac-sha384.c,v 1.2 2017/01/02 02:18:30 schmonz Exp $

Rename hmac to bghmac.

--- crypto/hmac-sha384.c.orig	2016-12-18 09:59:03.209209425 +0000
+++ crypto/hmac-sha384.c
@@ -46,7 +46,7 @@ static void test_hmac(const char* key, c
   const str data_str = { (char*)data, strlen(data), 0 };
   unsigned char digest[SHA384_DIGEST_LENGTH];
   unsigned i;
-  hmac(&hmac_sha384, &key_str, &data_str, digest);
+  bghmac(&hmac_sha384, &key_str, &data_str, digest);
   for (i = 0; i < sizeof digest; ++i)
     obuf_putxw(&outbuf, digest[i], 2, '0');
   obuf_endl(&outbuf);

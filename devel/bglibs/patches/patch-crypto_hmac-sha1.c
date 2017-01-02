$NetBSD: patch-crypto_hmac-sha1.c,v 1.2 2017/01/02 02:18:30 schmonz Exp $

Rename hmac to bghmac.

--- crypto/hmac-sha1.c.orig	2016-12-18 09:59:10.547412663 +0000
+++ crypto/hmac-sha1.c
@@ -49,7 +49,7 @@ static void test_hmac(const char* key, c
   const str data_str = { (char*)data, strlen(data), 0 };
   unsigned char digest[SHA1_DIGEST_LENGTH];
   unsigned i;
-  hmac(&hmac_sha1, &key_str, &data_str, digest);
+  bghmac(&hmac_sha1, &key_str, &data_str, digest);
   for (i = 0; i < sizeof digest; ++i)
     obuf_putXw(&outbuf, digest[i], 2, '0');
   NL();

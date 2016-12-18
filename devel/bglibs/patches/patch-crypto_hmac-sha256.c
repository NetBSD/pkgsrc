$NetBSD: patch-crypto_hmac-sha256.c,v 1.1 2016/12/18 21:39:58 joerg Exp $

--- crypto/hmac-sha256.c.orig	2016-12-18 09:59:08.038143186 +0000
+++ crypto/hmac-sha256.c
@@ -45,7 +45,7 @@ static void test_hmac(const char* key, c
   const str data_str = { (char*)data, strlen(data), 0 };
   unsigned char digest[SHA256_DIGEST_LENGTH];
   unsigned i;
-  hmac(&hmac_sha256, &key_str, &data_str, digest);
+  bghmac(&hmac_sha256, &key_str, &data_str, digest);
   for (i = 0; i < sizeof digest; ++i)
     obuf_putxw(&outbuf, digest[i], 2, '0');
   obuf_endl(&outbuf);

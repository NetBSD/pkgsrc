$NetBSD: patch-crypto_hmac-md5.c,v 1.2 2017/01/02 02:18:30 schmonz Exp $

Rename hmac to bghmac.

--- crypto/hmac-md5.c.orig	2016-12-18 09:59:13.731995800 +0000
+++ crypto/hmac-md5.c
@@ -65,7 +65,7 @@ static void HMACTest(const char* key, co
   const str data_str = { (char*)data, strlen(data), 0 };
   unsigned char digest[128/8];
   unsigned i;
-  hmac(&hmac_md5, &key_str, &data_str, digest);
+  bghmac(&hmac_md5, &key_str, &data_str, digest);
   printf("HMAC (%d,%d) = ", key_str.len, data_str.len);
   for (i = 0; i < sizeof digest; ++i) printf("%02x", digest[i]);
   printf("\n");

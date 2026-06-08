$NetBSD: patch-ssl.c,v 1.4 2026/06/08 04:45:46 adam Exp $

Fix for Nettle 4.0.

use correct modulus and exponent in rdssl_rkey_get_exp_mod
commit 53ba87dc174175e98332e22355ad8662c02880d6

--- ssl.c.orig	2019-09-19 10:34:03.000000000 +0000
+++ ssl.c
@@ -41,7 +41,7 @@ rdssl_sha1_final(RDSSL_SHA1 * sha1, uint8 * out_data)
 void
 rdssl_sha1_final(RDSSL_SHA1 * sha1, uint8 * out_data)
 {
-	sha1_digest(sha1, SHA1_DIGEST_SIZE, out_data);
+	sha1_digest(sha1, out_data);
 }
 
 void
@@ -59,7 +59,7 @@ rdssl_md5_final(RDSSL_MD5 * md5, uint8 * out_data)
 void
 rdssl_md5_final(RDSSL_MD5 * md5, uint8 * out_data)
 {
-	md5_digest(md5, MD5_DIGEST_SIZE, out_data);
+	md5_digest(md5, out_data);
 }
 
 void
@@ -307,10 +307,10 @@ rdssl_rkey_get_exp_mod(RDSSL_RKEY * rkey, uint8 * expo
 {
 	size_t outlen;
 
-	outlen = (mpz_sizeinbase(modulus, 2) + 7) / 8;
+	outlen = (mpz_sizeinbase(rkey->n, 2) + 7) / 8;
 	if (outlen > max_mod_len)
 		return 1;
-	outlen = (mpz_sizeinbase(exponent, 2) + 7) / 8;
+	outlen = (mpz_sizeinbase(rkey->e, 2) + 7) / 8;
 	if (outlen > max_exp_len)
 		return 1;
 
@@ -360,5 +360,5 @@ rdssl_hmac_md5(const void *key, int key_len, const uns
 
 	hmac_md5_set_key(&ctx, key_len, key);
 	hmac_md5_update(&ctx, msg_len, msg);
-	hmac_md5_digest(&ctx, MD5_DIGEST_SIZE, md);
+	hmac_md5_digest(&ctx, md);
 }

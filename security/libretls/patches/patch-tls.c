$NetBSD: patch-tls.c,v 1.2 2023/11/08 14:10:20 schmonz Exp $

Portability fix for OpenSSL 3.x.

With OpenSSL 3.x the EVP_PKEY_get1_RSA returns a cached copy of the
provider's key, so changing it is meaningless, since other get1/get0
calls will return the previously cached copy. Instead, we have to
re-assign the changed rsa after the edit.

Adapted from OpenSMTPD's libtls compat library. 

--- tls.c.orig	2022-12-23 22:19:37.000000000 +0000
+++ tls.c
@@ -466,7 +466,8 @@ tls_keypair_setup_pkey(struct tls *ctx, 
 	switch (EVP_PKEY_id(pkey)) {
 	case EVP_PKEY_RSA:
 		if ((rsa = EVP_PKEY_get1_RSA(pkey)) == NULL ||
-		    RSA_set_ex_data(rsa, 0, keypair->pubkey_hash) == 0) {
+		    RSA_set_ex_data(rsa, 0, keypair->pubkey_hash) == 0 ||
+		    EVP_PKEY_set1_RSA(pkey, rsa) == 0) {
 			tls_set_errorx(ctx, "RSA key setup failure");
 			goto err;
 		}
@@ -481,7 +482,8 @@ tls_keypair_setup_pkey(struct tls *ctx, 
 		break;
 	case EVP_PKEY_EC:
 		if ((eckey = EVP_PKEY_get1_EC_KEY(pkey)) == NULL ||
-		    EC_KEY_set_ex_data(eckey, 0, keypair->pubkey_hash) == 0) {
+		    EC_KEY_set_ex_data(eckey, 0, keypair->pubkey_hash) == 0 ||
+		    EVP_PKEY_set1_EC_KEY(pkey, eckey) == 0) {
 			tls_set_errorx(ctx, "EC key setup failure");
 			goto err;
 		}

$NetBSD: patch-ssl.c,v 1.3 2020/02/04 09:15:51 markd Exp $

use correct modulus and exponent in rdssl_rkey_get_exp_mod
commit 53ba87dc174175e98332e22355ad8662c02880d6

--- ssl.c.orig	2019-09-19 10:34:03.000000000 +0000
+++ ssl.c
@@ -307,10 +307,10 @@ rdssl_rkey_get_exp_mod(RDSSL_RKEY * rkey
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
 

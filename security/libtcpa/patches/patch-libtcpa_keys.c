$NetBSD: patch-libtcpa_keys.c,v 1.2 2020/10/26 10:04:12 schmonz Exp $

Fix build with OpenSSL 1.1.

--- libtcpa/keys.c.orig	2020-03-27 18:48:00.249254812 +0000
+++ libtcpa/keys.c
@@ -452,7 +452,6 @@ RSA *convpubkey(pubkeydata * k)
     BN_bin2bn(k->modulus, k->keylength, mod);
     BN_bin2bn(k->exponent, k->expsize, exp);
     /* set up the RSA public key structure */
-    rsa->n = mod;
-    rsa->e = exp;
+    RSA_set0_key(rsa, mod, exp, NULL);
     return rsa;
 }

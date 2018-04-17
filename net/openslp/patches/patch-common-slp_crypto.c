$NetBSD: patch-common-slp_crypto.c,v 1.1 2018/04/17 18:42:10 mrg Exp $

port to OpenSSL 1.1.

--- common/slp_crypto.c.orig	2005-02-08 14:23:27.000000000 -0800
+++ common/slp_crypto.c	2018-04-17 01:27:35.975421083 -0700
@@ -90,11 +90,21 @@
     result =  DSA_new();
     if(result)
     {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         result->p = BN_dup(dsa->p);
         result->q = BN_dup(dsa->q);
         result->g = BN_dup(dsa->g);
         result->priv_key = BN_dup(dsa->priv_key);
         result->pub_key = BN_dup(dsa->pub_key);
+#else
+        const BIGNUM *p, *q, *g;
+        const BIGNUM *pub_key, *priv_key;
+
+        DSA_get0_pqg(dsa, &p, &q, &g);
+        DSA_set0_pqg(result, BN_dup(p), BN_dup(q), BN_dup(g));
+        DSA_get0_key(dsa, &pub_key, &priv_key);
+        DSA_set0_key(result, BN_dup(pub_key), BN_dup(priv_key));
+#endif
     }
 
     return result;

$NetBSD: patch-iked_crypto__impl.h,v 1.1 2018/05/29 01:22:50 christos Exp $

Make unmodified argument const

--- iked/crypto_impl.h	2010-02-01 05:30:51.000000000 -0500
+++ iked/crypto_impl.h	2018-05-28 16:44:16.016528535 -0400
@@ -246,7 +246,7 @@
 extern int eay_revbnl (rc_vchar_t *);
 #include <openssl/bn.h>
 extern int eay_v2bn (BIGNUM **, rc_vchar_t *);
-extern int eay_bn2v (rc_vchar_t **, BIGNUM *);
+extern int eay_bn2v (rc_vchar_t **, const BIGNUM *);
 
 extern const char *eay_version (void);
 

$NetBSD: patch-RSA.xs,v 1.1 2018/02/25 18:53:48 wiz Exp $

From b3747e625780be90dcff11c2d9e91048016bb4d0 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Petr=20P=C3=ADsa=C5=99?= <ppisar@redhat.com>
Date: Thu, 13 Oct 2016 18:14:17 +0200
Subject: [PATCH] Adapt to OpenSSL 1.1.0
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

OpenSSL 1.1.0 hid structure internals and provided methods for getting
and settting the internal values. This patch modifes the code so that
it can be built with OpenSSL 1.1.0 as well as with the older one.

CPAN RT#117481

--- RSA.xs.orig	2011-08-24 22:57:35.000000000 +0000
+++ RSA.xs
@@ -49,7 +49,13 @@ void croakSsl(char* p_file, int p_line)
 
 char _is_private(rsaData* p_rsa)
 {
-    return(p_rsa->rsa->d != NULL);
+    const BIGNUM *d;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    d = p_rsa->rsa->d;
+#else
+    RSA_get0_key(p_rsa->rsa, NULL, NULL, &d);
+#endif
+    return(d != NULL);
 }
 
 SV* make_rsa_obj(SV* p_proto, RSA* p_rsa)
@@ -136,7 +142,7 @@ unsigned char* get_message_digest(SV* te
     }
 }
 
-SV* bn2sv(BIGNUM* p_bn)
+SV* bn2sv(const BIGNUM* p_bn)
 {
     return p_bn != NULL
         ? sv_2mortal(newSViv((IV) BN_dup(p_bn)))
@@ -317,6 +323,9 @@ _new_key_from_parameters(proto, n, e, d,
     BN_CTX* ctx;
     BIGNUM* p_minus_1 = NULL;
     BIGNUM* q_minus_1 = NULL;
+    BIGNUM* dmp1 = NULL;
+    BIGNUM* dmq1 = NULL;
+    BIGNUM* iqmp = NULL;
     int error;
   CODE:
 {
@@ -325,8 +334,10 @@ _new_key_from_parameters(proto, n, e, d,
         croak("At least a modulous and public key must be provided");
     }
     CHECK_OPEN_SSL(rsa = RSA_new());
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     rsa->n = n;
     rsa->e = e;
+#endif
     if (p || q)
     {
         error = 0;
@@ -341,8 +352,12 @@ _new_key_from_parameters(proto, n, e, d,
             q = BN_new();
             THROW(BN_div(q, NULL, n, p, ctx));
         }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         rsa->p = p;
         rsa->q = q;
+#else
+        THROW(RSA_set0_factors(rsa, p, q));
+#endif
         THROW(p_minus_1 = BN_new());
         THROW(BN_sub(p_minus_1, p, BN_value_one()));
         THROW(q_minus_1 = BN_new());
@@ -353,17 +368,32 @@ _new_key_from_parameters(proto, n, e, d,
             THROW(BN_mul(d, p_minus_1, q_minus_1, ctx));
             THROW(BN_mod_inverse(d, e, d, ctx));
         }
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         rsa->d = d;
-        THROW(rsa->dmp1 = BN_new());
-        THROW(BN_mod(rsa->dmp1, d, p_minus_1, ctx));
-        THROW(rsa->dmq1 = BN_new());
-        THROW(BN_mod(rsa->dmq1, d, q_minus_1, ctx));
-        THROW(rsa->iqmp = BN_new());
-        THROW(BN_mod_inverse(rsa->iqmp, q, p, ctx));
+#else
+        THROW(RSA_set0_key(rsa, n, e, d));
+#endif
+        THROW(dmp1 = BN_new());
+        THROW(BN_mod(dmp1, d, p_minus_1, ctx));
+        THROW(dmq1 = BN_new());
+        THROW(BN_mod(dmq1, d, q_minus_1, ctx));
+        THROW(iqmp = BN_new());
+        THROW(BN_mod_inverse(iqmp, q, p, ctx));
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+        rsa->dmp1 = dmp1;
+        rsa->dmq1 = dmq1;
+        rsa->iqmp = iqmp;
+#else
+        THROW(RSA_set0_crt_params(rsa, dmp1, dmq1, iqmp));
+#endif
+        dmp1 = dmq1 = iqmp = NULL;
         THROW(RSA_check_key(rsa) == 1);
      err:
         if (p_minus_1) BN_clear_free(p_minus_1);
         if (q_minus_1) BN_clear_free(q_minus_1);
+        if (dmp1) BN_clear_free(dmp1);
+        if (dmq1) BN_clear_free(dmq1);
+        if (iqmp) BN_clear_free(iqmp);
         if (ctx) BN_CTX_free(ctx);
         if (error)
         {
@@ -373,7 +403,11 @@ _new_key_from_parameters(proto, n, e, d,
     }
     else
     {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
         rsa->d = d;
+#else
+        CHECK_OPEN_SSL(RSA_set0_key(rsa, n, e, d));
+#endif
     }
     RETVAL = make_rsa_obj(proto, rsa);
 }
@@ -383,18 +417,41 @@ _new_key_from_parameters(proto, n, e, d,
 void
 _get_key_parameters(p_rsa)
     rsaData* p_rsa;
+PREINIT:
+    const BIGNUM* n;
+    const BIGNUM* e;
+    const BIGNUM* d;
+    const BIGNUM* p;
+    const BIGNUM* q;
+    const BIGNUM* dmp1;
+    const BIGNUM* dmq1;
+    const BIGNUM* iqmp;
 PPCODE:
 {
     RSA* rsa;
     rsa = p_rsa->rsa;
-    XPUSHs(bn2sv(rsa->n));
-    XPUSHs(bn2sv(rsa->e));
-    XPUSHs(bn2sv(rsa->d));
-    XPUSHs(bn2sv(rsa->p));
-    XPUSHs(bn2sv(rsa->q));
-    XPUSHs(bn2sv(rsa->dmp1));
-    XPUSHs(bn2sv(rsa->dmq1));
-    XPUSHs(bn2sv(rsa->iqmp));
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    n = rsa->n;
+    e = rsa->e;
+    d = rsa->d;
+    p = rsa->p;
+    q = rsa->q;
+    dmp1 = rsa->dmp1;
+    dmq1 = rsa->dmq1;
+    iqmp = rsa->iqmp;
+#else
+    RSA_get0_key(rsa, &n, &e, &d);
+    RSA_get0_factors(rsa, &p, &q);
+    RSA_get0_crt_params(rsa, &dmp1, &dmq1, &iqmp);
+#endif
+    XPUSHs(bn2sv(n));
+    XPUSHs(bn2sv(e));
+    XPUSHs(bn2sv(d));
+    XPUSHs(bn2sv(p));
+    XPUSHs(bn2sv(q));
+    XPUSHs(bn2sv(dmp1));
+    XPUSHs(bn2sv(dmq1));
+    XPUSHs(bn2sv(iqmp));
 }
 
 SV*

$NetBSD: patch-lib_openssl_hmac.c,v 1.1 2023/01/30 19:38:06 nikita Exp $

The function hmac in hmac.c conflicts with hmac from stdlib on NetBSD.

--- lib/openssl/hmac.c.orig	2022-06-20 21:21:38.997255017 +0200
+++ lib/openssl/hmac.c	2022-06-20 21:22:08.635313366 +0200
@@ -95,7 +95,7 @@
 }
 
 static HMAC_CTX *
-hmac(const jose_hook_alg_t *alg, jose_cfg_t *cfg,
+jhmac(const jose_hook_alg_t *alg, jose_cfg_t *cfg,
      const json_t *sig, const json_t *jwk)
 {
     uint8_t key[KEYMAX] = {};
@@ -251,7 +251,7 @@
 
     i->obj = json_incref(jws);
     i->sig = json_incref(sig);
-    i->hctx = hmac(alg, cfg, sig, jwk);
+    i->hctx = jhmac(alg, cfg, sig, jwk);
     if (!i->obj || !i->sig || !i->hctx)
         return NULL;
 
@@ -275,7 +275,7 @@
     io->free = io_free;
 
     i->sig = json_incref((json_t *) sig);
-    i->hctx = hmac(alg, cfg, sig, jwk);
+    i->hctx = jhmac(alg, cfg, sig, jwk);
     if (!i->sig || !i->hctx)
         return NULL;
 

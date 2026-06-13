$NetBSD: patch-src_nettls-gnutls_nettle.c,v 1.1 2026/06/13 06:15:19 adam Exp $

Fix for Nettle 4.0.

--- src/nettls-gnutls/nettle.c.orig	2026-06-13 06:09:05.768759232 +0000
+++ src/nettls-gnutls/nettle.c
@@ -292,7 +292,7 @@ static net_nettle_gcm_aes_ctx_t net_nettle_gcm_aes_ini
 
 static net_nettle_gcm_aes_ctx_t net_nettle_gcm_aes_init(void) {
 #ifdef HAVE_NETTLE_GCM_H
-    return stat_alloc(sizeof(struct gcm_aes_ctx));
+    return stat_alloc(sizeof(struct gcm_aes256_ctx));
 #else
     return NULL;
 #endif
@@ -341,7 +341,7 @@ static void net_nettle_hash_digest(net_nettle_hash_t h
                                    net_nettle_hash_ctx_t ctx,
                                    unsigned int length,
                                    uint8_t *dst) {
-    hash->digest(ctx, length, dst);
+    hash->digest(ctx, dst);
 }
 
 #ifndef HAVE_FUN_nettle_get_hashes

$NetBSD: patch-nettle-internal.h,v 1.1 2011/08/25 20:17:26 tron Exp $

Fix linking problem under Mac OS X.

--- nettle-internal.h.orig	2011-07-11 14:59:25.000000000 +0100
+++ nettle-internal.h	2011-08-25 21:14:05.000000000 +0100
@@ -108,20 +108,20 @@
   (nettle_hash_digest_func *) type##_##name##_digest,	\
 }
 
-const struct nettle_aead nettle_gcm_aes128;
-const struct nettle_aead nettle_gcm_aes192;
-const struct nettle_aead nettle_gcm_aes256;
+extern const struct nettle_aead nettle_gcm_aes128;
+extern const struct nettle_aead nettle_gcm_aes192;
+extern const struct nettle_aead nettle_gcm_aes256;
 
-const struct nettle_aead nettle_gcm_camellia128;
-const struct nettle_aead nettle_gcm_camellia192;
-const struct nettle_aead nettle_gcm_camellia256;
+extern const struct nettle_aead nettle_gcm_camellia128;
+extern const struct nettle_aead nettle_gcm_camellia192;
+extern const struct nettle_aead nettle_gcm_camellia256;
 
-const struct nettle_aead nettle_gcm_serpent128;
-const struct nettle_aead nettle_gcm_serpent192;
-const struct nettle_aead nettle_gcm_serpent256;
+extern const struct nettle_aead nettle_gcm_serpent128;
+extern const struct nettle_aead nettle_gcm_serpent192;
+extern const struct nettle_aead nettle_gcm_serpent256;
 
-const struct nettle_aead nettle_gcm_twofish128;
-const struct nettle_aead nettle_gcm_twofish192;
-const struct nettle_aead nettle_gcm_twofish256;
+extern const struct nettle_aead nettle_gcm_twofish128;
+extern const struct nettle_aead nettle_gcm_twofish192;
+extern const struct nettle_aead nettle_gcm_twofish256;
 
 #endif /* NETTLE_INTERNAL_H_INCLUDED */

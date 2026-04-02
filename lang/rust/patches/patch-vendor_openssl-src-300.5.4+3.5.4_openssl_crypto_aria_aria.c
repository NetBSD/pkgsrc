$NetBSD: patch-vendor_openssl-src-300.5.4+3.5.4_openssl_crypto_aria_aria.c,v 1.1 2026/04/02 19:06:35 wiz Exp $

Make this build also if bswap32 is already defined, as for NetBSD/i586.

--- vendor/openssl-src-300.5.4+3.5.4/openssl/crypto/aria/aria.c.orig	2025-11-02 17:14:42.569500518 +0000
+++ vendor/openssl-src-300.5.4+3.5.4/openssl/crypto/aria/aria.c
@@ -32,9 +32,11 @@
 #define rotl32(v, r) (((uint32_t)(v) << (r)) | ((uint32_t)(v) >> (32 - r)))
 #define rotr32(v, r) (((uint32_t)(v) >> (r)) | ((uint32_t)(v) << (32 - r)))
 
+#ifndef bswap32
 #define bswap32(v)                                          \
     (((v) << 24) ^ ((v) >> 24) ^                            \
     (((v) & 0x0000ff00) << 8) ^ (((v) & 0x00ff0000) >> 8))
+#endif
 
 #define GET_U8_BE(X, Y) ((uint8_t)((X) >> ((3 - Y) * 8)))
 #define GET_U32_BE(X, Y) (                                  \

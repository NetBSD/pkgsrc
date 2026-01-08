$NetBSD: patch-src_libsodium_crypto__ipcrypt_crypto_ipcrypt.c,v 1.2 2026/01/08 14:59:35 wiz Exp $

Export missing crypto_ipcrypt_nd_keygen() helper function.
https://github.com/jedisct1/libsodium/commit/60b528c3dd0da9de96c1a237c8acc82697aa9f15

--- src/libsodium/crypto_ipcrypt/crypto_ipcrypt.c	2026-01-06 14:42:08.000000000 +0000
+++ src/libsodium/crypto_ipcrypt/crypto_ipcrypt.c
@@ -99,6 +99,12 @@ crypto_ipcrypt_keygen(unsigned char k[cr
 }
 
 void
+crypto_ipcrypt_nd_keygen(unsigned char k[crypto_ipcrypt_ND_KEYBYTES])
+{
+    randombytes_buf(k, crypto_ipcrypt_ND_KEYBYTES);
+}
+
+void
 crypto_ipcrypt_ndx_keygen(unsigned char k[crypto_ipcrypt_NDX_KEYBYTES])
 {
     randombytes_buf(k, crypto_ipcrypt_NDX_KEYBYTES);

$NetBSD: patch-src_libsodium_crypto__ipcrypt_crypto_ipcrypt.c,v 1.1 2026/01/08 14:54:46 adam Exp $

Export missing crypto_ipcrypt_nd_keygen() helper function.

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

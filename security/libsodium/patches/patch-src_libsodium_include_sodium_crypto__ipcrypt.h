$NetBSD: patch-src_libsodium_include_sodium_crypto__ipcrypt.h,v 1.1 2026/01/08 14:54:46 adam Exp $

Export missing crypto_ipcrypt_nd_keygen() helper function.

--- src/libsodium/include/sodium/crypto_ipcrypt.h	2026-01-06 14:42:08.000000000 +0000
+++ src/libsodium/include/sodium/crypto_ipcrypt.h
@@ -64,6 +64,10 @@ SODIUM_EXPORT
 void crypto_ipcrypt_keygen(unsigned char k[crypto_ipcrypt_KEYBYTES]) __attribute__((nonnull));
 
 SODIUM_EXPORT
+void crypto_ipcrypt_nd_keygen(unsigned char k[crypto_ipcrypt_ND_KEYBYTES])
+    __attribute__((nonnull));
+
+SODIUM_EXPORT
 void crypto_ipcrypt_ndx_keygen(unsigned char k[crypto_ipcrypt_NDX_KEYBYTES])
     __attribute__((nonnull));
 

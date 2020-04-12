$NetBSD: patch-lib_crypto_CipherContext.h,v 1.1 2020/04/12 19:45:51 joerg Exp $

OpenSSL 1.1 compat.

--- lib/crypto/CipherContext.h.orig	2020-04-12 15:12:22.390595514 +0000
+++ lib/crypto/CipherContext.h
@@ -127,7 +127,7 @@ public:
 #endif
 	
 private:
-	EVP_CIPHER_CTX ctx;
+	EVP_CIPHER_CTX *ctx;
 	bool mInitialised;
 	bool mWithinTransform;
 	bool mPaddingOn;

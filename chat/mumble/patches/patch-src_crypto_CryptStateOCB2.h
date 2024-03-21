$NetBSD: patch-src_crypto_CryptStateOCB2.h,v 1.1 2024/03/21 10:34:10 nia Exp $

From f4cea62ed95e4967d8591f25e903f5e8fc2e2a30 Mon Sep 17 00:00:00 2001
From: Terry Geng <terry@terriex.com>
Date: Mon, 6 Dec 2021 10:45:11 -0500
Subject: [PATCH] BUILD(crypto): Migrate to OpenSSL 3.0-compatible API

OpenSSL 3.0 deprecated several low-level APIs and the usage of them
caused errors/warnings that prevent the binary from being built against
OpenSSL 3.0.
Some primitive efforts have been made in #5317 but were incomplete.
This commit follows https://www.openssl.org/docs/man3.0/man7/migration_guide.html,
https://code.woboq.org/qt6/qtopcua/src/opcua/x509/qopcuakeypair_openssl.cpp.html,
and clears all errors/warnings related to the usage of deprecated APIs.

--- src/crypto/CryptStateOCB2.h.orig	2022-09-13 17:24:40.000000000 +0000
+++ src/crypto/CryptStateOCB2.h
@@ -8,8 +8,9 @@
 
 #include "CryptState.h"
 
-#include <openssl/aes.h>
+#include <openssl/evp.h>
 
+#define AES_BLOCK_SIZE 16
 #define AES_KEY_SIZE_BITS 128
 #define AES_KEY_SIZE_BYTES (AES_KEY_SIZE_BITS / 8)
 
@@ -17,7 +18,7 @@
 class CryptStateOCB2 : public CryptState {
 public:
 	CryptStateOCB2();
-	~CryptStateOCB2(){};
+	~CryptStateOCB2() noexcept override;
 
 	virtual bool isValid() const Q_DECL_OVERRIDE;
 	virtual void genKey() Q_DECL_OVERRIDE;
@@ -43,8 +44,10 @@ private:
 	unsigned char decrypt_iv[AES_BLOCK_SIZE];
 	unsigned char decrypt_history[0x100];
 
-	AES_KEY encrypt_key;
-	AES_KEY decrypt_key;
+	EVP_CIPHER_CTX *enc_ctx_ocb_enc;
+	EVP_CIPHER_CTX *dec_ctx_ocb_enc;
+	EVP_CIPHER_CTX *enc_ctx_ocb_dec;
+	EVP_CIPHER_CTX *dec_ctx_ocb_dec;
 };
 
 

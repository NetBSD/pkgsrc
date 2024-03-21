$NetBSD: patch-src_crypto_CryptStateOCB2.cpp,v 1.1 2024/03/21 10:34:10 nia Exp $

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

--- src/crypto/CryptStateOCB2.cpp.orig	2022-09-13 17:24:40.000000000 +0000
+++ src/crypto/CryptStateOCB2.cpp
@@ -30,7 +30,9 @@
 #include <cstring>
 #include <openssl/rand.h>
 
-CryptStateOCB2::CryptStateOCB2() : CryptState() {
+CryptStateOCB2::CryptStateOCB2()
+	: CryptState(), enc_ctx_ocb_enc(EVP_CIPHER_CTX_new()), dec_ctx_ocb_enc(EVP_CIPHER_CTX_new()),
+	  enc_ctx_ocb_dec(EVP_CIPHER_CTX_new()), dec_ctx_ocb_dec(EVP_CIPHER_CTX_new()) {
 	for (int i = 0; i < 0x100; i++)
 		decrypt_history[i] = 0;
 	memset(raw_key, 0, AES_KEY_SIZE_BYTES);
@@ -38,6 +40,13 @@ CryptStateOCB2::CryptStateOCB2() : Crypt
 	memset(decrypt_iv, 0, AES_BLOCK_SIZE);
 }
 
+CryptStateOCB2::~CryptStateOCB2() noexcept {
+	EVP_CIPHER_CTX_free(enc_ctx_ocb_enc);
+	EVP_CIPHER_CTX_free(dec_ctx_ocb_enc);
+	EVP_CIPHER_CTX_free(enc_ctx_ocb_dec);
+	EVP_CIPHER_CTX_free(dec_ctx_ocb_dec);
+}
+
 bool CryptStateOCB2::isValid() const {
 	return bInit;
 }
@@ -46,8 +55,6 @@ void CryptStateOCB2::genKey() {
 	CryptographicRandom::fillBuffer(raw_key, AES_KEY_SIZE_BYTES);
 	CryptographicRandom::fillBuffer(encrypt_iv, AES_BLOCK_SIZE);
 	CryptographicRandom::fillBuffer(decrypt_iv, AES_BLOCK_SIZE);
-	AES_set_encrypt_key(raw_key, AES_KEY_SIZE_BITS, &encrypt_key);
-	AES_set_decrypt_key(raw_key, AES_KEY_SIZE_BITS, &decrypt_key);
 	bInit = true;
 }
 
@@ -56,8 +63,6 @@ bool CryptStateOCB2::setKey(const std::s
 		memcpy(raw_key, rkey.data(), AES_KEY_SIZE_BYTES);
 		memcpy(encrypt_iv, eiv.data(), AES_BLOCK_SIZE);
 		memcpy(decrypt_iv, div.data(), AES_BLOCK_SIZE);
-		AES_set_encrypt_key(raw_key, AES_KEY_SIZE_BITS, &encrypt_key);
-		AES_set_decrypt_key(raw_key, AES_KEY_SIZE_BITS, &decrypt_key);
 		bInit = true;
 		return true;
 	}
@@ -256,10 +261,27 @@ static void inline ZERO(keyblock &block)
 		block[i] = 0;
 }
 
-#define AESencrypt(src, dst, key) \
-	AES_encrypt(reinterpret_cast< const unsigned char * >(src), reinterpret_cast< unsigned char * >(dst), key);
-#define AESdecrypt(src, dst, key) \
-	AES_decrypt(reinterpret_cast< const unsigned char * >(src), reinterpret_cast< unsigned char * >(dst), key);
+#define AESencrypt_ctx(src, dst, key, enc_ctx)                                                      \
+	{                                                                                               \
+		int outlen = 0;                                                                             \
+		EVP_EncryptInit_ex(enc_ctx, EVP_aes_128_ecb(), NULL, key, NULL);                            \
+		EVP_CIPHER_CTX_set_padding(enc_ctx, 0);                                                     \
+		EVP_EncryptUpdate(enc_ctx, reinterpret_cast< unsigned char * >(dst), &outlen,               \
+						  reinterpret_cast< const unsigned char * >(src), AES_BLOCK_SIZE);          \
+		EVP_EncryptFinal_ex(enc_ctx, reinterpret_cast< unsigned char * >((dst) + outlen), &outlen); \
+	}
+#define AESdecrypt_ctx(src, dst, key, dec_ctx)                                                      \
+	{                                                                                               \
+		int outlen = 0;                                                                             \
+		EVP_DecryptInit_ex(dec_ctx, EVP_aes_128_ecb(), NULL, key, NULL);                            \
+		EVP_CIPHER_CTX_set_padding(dec_ctx, 0);                                                     \
+		EVP_DecryptUpdate(dec_ctx, reinterpret_cast< unsigned char * >(dst), &outlen,               \
+						  reinterpret_cast< const unsigned char * >(src), AES_BLOCK_SIZE);          \
+		EVP_DecryptFinal_ex(dec_ctx, reinterpret_cast< unsigned char * >((dst) + outlen), &outlen); \
+	}
+
+#define AESencrypt(src, dst, key) AESencrypt_ctx(src, dst, key, enc_ctx_ocb_enc)
+#define AESdecrypt(src, dst, key) AESdecrypt_ctx(src, dst, key, dec_ctx_ocb_enc)
 
 bool CryptStateOCB2::ocb_encrypt(const unsigned char *plain, unsigned char *encrypted, unsigned int len,
 								 const unsigned char *nonce, unsigned char *tag, bool modifyPlainOnXEXStarAttack) {
@@ -267,7 +289,7 @@ bool CryptStateOCB2::ocb_encrypt(const u
 	bool success = true;
 
 	// Initialize
-	AESencrypt(nonce, delta, &encrypt_key);
+	AESencrypt(nonce, delta, raw_key);
 	ZERO(checksum);
 
 	while (len > AES_BLOCK_SIZE) {
@@ -299,7 +321,7 @@ bool CryptStateOCB2::ocb_encrypt(const u
 		if (flipABit) {
 			*reinterpret_cast< unsigned char * >(tmp) ^= 1;
 		}
-		AESencrypt(tmp, tmp, &encrypt_key);
+		AESencrypt(tmp, tmp, raw_key);
 		XOR(reinterpret_cast< subblock * >(encrypted), delta, tmp);
 		XOR(checksum, checksum, reinterpret_cast< const subblock * >(plain));
 		if (flipABit) {
@@ -315,7 +337,7 @@ bool CryptStateOCB2::ocb_encrypt(const u
 	ZERO(tmp);
 	tmp[BLOCKSIZE - 1] = SWAPPED(len * 8);
 	XOR(tmp, tmp, delta);
-	AESencrypt(tmp, pad, &encrypt_key);
+	AESencrypt(tmp, pad, raw_key);
 	memcpy(tmp, plain, len);
 	memcpy(reinterpret_cast< unsigned char * >(tmp) + len, reinterpret_cast< const unsigned char * >(pad) + len,
 		   AES_BLOCK_SIZE - len);
@@ -325,24 +347,30 @@ bool CryptStateOCB2::ocb_encrypt(const u
 
 	S3(delta);
 	XOR(tmp, delta, checksum);
-	AESencrypt(tmp, tag, &encrypt_key);
+	AESencrypt(tmp, tag, raw_key);
 
 	return success;
 }
 
+#undef AESencrypt
+#undef AESdecrypt
+
+#define AESencrypt(src, dst, key) AESencrypt_ctx(src, dst, key, enc_ctx_ocb_dec)
+#define AESdecrypt(src, dst, key) AESdecrypt_ctx(src, dst, key, dec_ctx_ocb_dec)
+
 bool CryptStateOCB2::ocb_decrypt(const unsigned char *encrypted, unsigned char *plain, unsigned int len,
 								 const unsigned char *nonce, unsigned char *tag) {
 	keyblock checksum, delta, tmp, pad;
 	bool success = true;
 
 	// Initialize
-	AESencrypt(nonce, delta, &encrypt_key);
+	AESencrypt(nonce, delta, raw_key);
 	ZERO(checksum);
 
 	while (len > AES_BLOCK_SIZE) {
 		S2(delta);
 		XOR(tmp, delta, reinterpret_cast< const subblock * >(encrypted));
-		AESdecrypt(tmp, tmp, &decrypt_key);
+		AESdecrypt(tmp, tmp, raw_key);
 		XOR(reinterpret_cast< subblock * >(plain), delta, tmp);
 		XOR(checksum, checksum, reinterpret_cast< const subblock * >(plain));
 		len -= AES_BLOCK_SIZE;
@@ -354,7 +382,7 @@ bool CryptStateOCB2::ocb_decrypt(const u
 	ZERO(tmp);
 	tmp[BLOCKSIZE - 1] = SWAPPED(len * 8);
 	XOR(tmp, tmp, delta);
-	AESencrypt(tmp, pad, &encrypt_key);
+	AESencrypt(tmp, pad, raw_key);
 	memset(tmp, 0, AES_BLOCK_SIZE);
 	memcpy(tmp, encrypted, len);
 	XOR(tmp, tmp, pad);
@@ -372,14 +400,14 @@ bool CryptStateOCB2::ocb_decrypt(const u
 
 	S3(delta);
 	XOR(tmp, delta, checksum);
-	AESencrypt(tmp, tag, &encrypt_key);
+	AESencrypt(tmp, tag, raw_key);
 
 	return success;
 }
 
+#undef AESencrypt
+#undef AESdecrypt
 #undef BLOCKSIZE
 #undef SHIFTBITS
 #undef SWAPPED
 #undef HIGHBIT
-#undef AES_encrypt
-#undef AES_decrypt

$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoKeyEC.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.cpp.orig	2015-02-03 00:57:48.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.cpp
@@ -128,10 +128,10 @@ OpenSSLCryptoKeyEC::OpenSSLCryptoKeyEC(E
 
 	// Create a new key to be loaded as we go
 
-	if (k == NULL || k->type != EVP_PKEY_EC)
+	if (k == NULL || EVP_PKEY_base_id(k) != EVP_PKEY_EC)
 		return;	// Nothing to do with us
 
-    mp_ecKey = EC_KEY_dup(k->pkey.ec);
+    mp_ecKey = EC_KEY_dup(EVP_PKEY_get0_EC_KEY(k));
 }
 
 // --------------------------------------------------------------------------------
@@ -162,9 +162,9 @@ bool OpenSSLCryptoKeyEC::verifyBase64Sig
 	unsigned char* sigVal = new unsigned char[sigLen + 1];
     ArrayJanitor<unsigned char> j_sigVal(sigVal);
 
-	EVP_ENCODE_CTX m_dctx;
-	EVP_DecodeInit(&m_dctx);
-	int rc = EVP_DecodeUpdate(&m_dctx,
+	EVP_ENCODE_CTX *m_dctx = EVP_ENCODE_CTX_new();
+	EVP_DecodeInit(m_dctx);
+	int rc = EVP_DecodeUpdate(m_dctx,
 						  sigVal,
 						  &sigValLen,
 						  (unsigned char *) cleanedBase64Signature,
@@ -177,7 +177,8 @@ bool OpenSSLCryptoKeyEC::verifyBase64Sig
 	}
 	int t = 0;
 
-	EVP_DecodeFinal(&m_dctx, &sigVal[sigValLen], &t);
+	EVP_DecodeFinal(m_dctx, &sigVal[sigValLen], &t);
+	EVP_ENCODE_CTX_free(m_dctx);
 
 	sigValLen += t;
 
@@ -189,8 +190,9 @@ bool OpenSSLCryptoKeyEC::verifyBase64Sig
 	// Translate to BNs by splitting in half, and thence to ECDSA_SIG
 
 	ECDSA_SIG * dsa_sig = ECDSA_SIG_new();
-	dsa_sig->r = BN_bin2bn(sigVal, sigValLen / 2, NULL);
-	dsa_sig->s = BN_bin2bn(&sigVal[sigValLen / 2], sigValLen / 2, NULL);
+	ECDSA_SIG_set0(dsa_sig,
+		BN_bin2bn(sigVal, sigValLen / 2, NULL),
+		BN_bin2bn(&sigVal[sigValLen / 2], sigValLen / 2, NULL));
 
 	// Now we have a signature and a key - lets check
 
@@ -228,6 +230,8 @@ unsigned int OpenSSLCryptoKeyEC::signBas
 	ECDSA_SIG * dsa_sig;
 
 	dsa_sig = ECDSA_do_sign(hashBuf, hashLen, mp_ecKey);
+	const BIGNUM *r, *s;
+	ECDSA_SIG_get0(dsa_sig, &r, &s);
 
 	if (dsa_sig == NULL) {
 		throw XSECCryptoException(XSECCryptoException::ECError,
@@ -263,14 +267,14 @@ unsigned int OpenSSLCryptoKeyEC::signBas
     memset(rawSigBuf, 0, keyLen * 2);
     ArrayJanitor<unsigned char> j_sigbuf(rawSigBuf);
 
-    unsigned int rawLen = (BN_num_bits(dsa_sig->r) + 7) / 8;
-    if (BN_bn2bin(dsa_sig->r, rawSigBuf + keyLen - rawLen) <= 0) {
+    unsigned int rawLen = (BN_num_bits(r) + 7) / 8;
+    if (BN_bn2bin(r, rawSigBuf + keyLen - rawLen) <= 0) {
 		throw XSECCryptoException(XSECCryptoException::ECError,
 			"OpenSSL:EC - Error copying signature 'r' value to buffer");
 	}
 
-	rawLen = (BN_num_bits(dsa_sig->s) + 7) / 8;
-    if (BN_bn2bin(dsa_sig->s, rawSigBuf + keyLen + keyLen - rawLen) <= 0) {
+	rawLen = (BN_num_bits(s) + 7) / 8;
+    if (BN_bn2bin(s, rawSigBuf + keyLen + keyLen - rawLen) <= 0) {
 		throw XSECCryptoException(XSECCryptoException::ECError,
 			"OpenSSL:EC - Error copying signature 's' value to buffer");
 	}

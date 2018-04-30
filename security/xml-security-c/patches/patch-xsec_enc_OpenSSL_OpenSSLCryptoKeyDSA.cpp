$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoKeyDSA.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp.orig	2015-01-29 02:52:17.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.cpp
@@ -64,13 +64,15 @@ XSECCryptoKey::KeyType OpenSSLCryptoKeyD
 	if (mp_dsaKey == NULL)
 		return KEY_NONE;
 
-	if (mp_dsaKey->priv_key != NULL && mp_dsaKey->pub_key != NULL)
+	const BIGNUM *pub_key = 0, *priv_key = 0;
+	DSA_get0_key(mp_dsaKey, &pub_key, &priv_key);
+	if (priv_key != NULL && pub_key != NULL)
 		return KEY_DSA_PAIR;
 
-	if (mp_dsaKey->priv_key != NULL)
+	if (priv_key != NULL)
 		return KEY_DSA_PRIVATE;
 
-	if (mp_dsaKey->pub_key != NULL)
+	if (pub_key != NULL)
 		return KEY_DSA_PUBLIC;
 
 	return KEY_NONE;
@@ -82,7 +84,7 @@ void OpenSSLCryptoKeyDSA::loadPBase64Big
 	if (mp_dsaKey == NULL)
 		mp_dsaKey = DSA_new();
 
-	mp_dsaKey->p = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	DSA_set0_pqg(mp_dsaKey, OpenSSLCryptoBase64::b642BN((char *) b64, len), 0, 0);
 
 }
 
@@ -91,7 +93,7 @@ void OpenSSLCryptoKeyDSA::loadQBase64Big
 	if (mp_dsaKey == NULL)
 		mp_dsaKey = DSA_new();
 
-	mp_dsaKey->q = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	DSA_set0_pqg(mp_dsaKey, 0, OpenSSLCryptoBase64::b642BN((char *) b64, len), 0);
 
 }
 
@@ -100,7 +102,7 @@ void OpenSSLCryptoKeyDSA::loadGBase64Big
 	if (mp_dsaKey == NULL)
 		mp_dsaKey = DSA_new();
 
-	mp_dsaKey->g = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	DSA_set0_pqg(mp_dsaKey, 0, 0, OpenSSLCryptoBase64::b642BN((char *) b64, len));
 
 }
 
@@ -109,7 +111,7 @@ void OpenSSLCryptoKeyDSA::loadYBase64Big
 	if (mp_dsaKey == NULL)
 		mp_dsaKey = DSA_new();
 
-	mp_dsaKey->pub_key = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	DSA_set0_key(mp_dsaKey, OpenSSLCryptoBase64::b642BN((char *) b64, len), 0);
 
 }
 
@@ -130,20 +132,15 @@ OpenSSLCryptoKeyDSA::OpenSSLCryptoKeyDSA
 
 	mp_dsaKey = DSA_new();
 
-	if (k == NULL || k->type != EVP_PKEY_DSA)
+	if (k == NULL || EVP_PKEY_base_id(k) != EVP_PKEY_DSA)
 		return;	// Nothing to do with us
 
-
-	if (k->pkey.dsa->p)
-		mp_dsaKey->p = BN_dup(k->pkey.dsa->p);
-	if (k->pkey.dsa->q)
-		mp_dsaKey->q = BN_dup(k->pkey.dsa->q);
-	if (k->pkey.dsa->g)
-		mp_dsaKey->g = BN_dup(k->pkey.dsa->g);
-	if (k->pkey.dsa->pub_key)
-		mp_dsaKey->pub_key = BN_dup(k->pkey.dsa->pub_key);
-	if (k->pkey.dsa->priv_key)
-		mp_dsaKey->priv_key = BN_dup(k->pkey.dsa->priv_key);
+	DSA *dsa = EVP_PKEY_get0_DSA(k);
+	const BIGNUM *p = 0, *q = 0, *g = 0, *pub_key = 0, *priv_key = 0;
+	DSA_get0_pqg(dsa, &p, &q, &g);
+	DSA_get0_key(dsa, &pub_key, &priv_key);
+	DSA_set0_pqg(mp_dsaKey, BN_dup(p), BN_dup(q), BN_dup(g));
+	DSA_set0_key(mp_dsaKey, BN_dup(pub_key), BN_dup(priv_key));
 
 }
 
@@ -175,9 +172,9 @@ bool OpenSSLCryptoKeyDSA::verifyBase64Si
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
@@ -190,7 +187,8 @@ bool OpenSSLCryptoKeyDSA::verifyBase64Si
 	}
 	int t = 0;
 
-	EVP_DecodeFinal(&m_dctx, &sigVal[sigValLen], &t);
+	EVP_DecodeFinal(m_dctx, &sigVal[sigValLen], &t);
+	EVP_ENCODE_CTX_free(m_dctx);
 
 	sigValLen += t;
 
@@ -223,12 +221,7 @@ bool OpenSSLCryptoKeyDSA::verifyBase64Si
 	}
 
 	DSA_SIG * dsa_sig = DSA_SIG_new();
-
-	dsa_sig->r = BN_dup(R);
-	dsa_sig->s = BN_dup(S);
-
-	BN_free(R);
-	BN_free(S);
+	DSA_SIG_set0(dsa_sig, R, S);
 
 	// Now we have a signature and a key - lets check
 
@@ -267,6 +260,8 @@ unsigned int OpenSSLCryptoKeyDSA::signBa
 	DSA_SIG * dsa_sig;
 
 	dsa_sig = DSA_do_sign(hashBuf, hashLen, mp_dsaKey);
+	const BIGNUM *r = 0, *s = 0;
+	DSA_SIG_get0(dsa_sig, &r, &s);
 
 	if (dsa_sig == NULL) {
 
@@ -277,10 +272,10 @@ unsigned int OpenSSLCryptoKeyDSA::signBa
 
 	// Now turn the signature into a base64 string
 
-	unsigned char* rawSigBuf = new unsigned char[(BN_num_bits(dsa_sig->r) + BN_num_bits(dsa_sig->s) + 7) / 8];
+	unsigned char* rawSigBuf = new unsigned char[(BN_num_bits(r) + BN_num_bits(s) + 7) / 8];
     ArrayJanitor<unsigned char> j_sigbuf(rawSigBuf);
 	
-    unsigned int rawLen = BN_bn2bin(dsa_sig->r, rawSigBuf);
+    unsigned int rawLen = BN_bn2bin(r, rawSigBuf);
 
 	if (rawLen <= 0) {
 
@@ -289,7 +284,7 @@ unsigned int OpenSSLCryptoKeyDSA::signBa
 
 	}
 
-	unsigned int rawLenS = BN_bn2bin(dsa_sig->s, (unsigned char *) &rawSigBuf[rawLen]);
+	unsigned int rawLenS = BN_bn2bin(s, (unsigned char *) &rawSigBuf[rawLen]);
 
 	if (rawLenS <= 0) {
 
@@ -339,16 +334,11 @@ XSECCryptoKey * OpenSSLCryptoKeyDSA::clo
 	ret->mp_dsaKey = DSA_new();
 
 	// Duplicate parameters
-	if (mp_dsaKey->p)
-		ret->mp_dsaKey->p = BN_dup(mp_dsaKey->p);
-	if (mp_dsaKey->q)
-		ret->mp_dsaKey->q = BN_dup(mp_dsaKey->q);
-	if (mp_dsaKey->g)
-		ret->mp_dsaKey->g = BN_dup(mp_dsaKey->g);
-	if (mp_dsaKey->pub_key)
-		ret->mp_dsaKey->pub_key = BN_dup(mp_dsaKey->pub_key);
-	if (mp_dsaKey->priv_key)
-		ret->mp_dsaKey->priv_key = BN_dup(mp_dsaKey->priv_key);
+	const BIGNUM *p = 0, *q = 0, *g = 0, *pub_key = 0, *priv_key = 0;
+	DSA_get0_pqg(mp_dsaKey, &p, &q, &g);
+	DSA_get0_key(mp_dsaKey, &pub_key, &priv_key);
+	DSA_set0_pqg(ret->mp_dsaKey, BN_dup(p), BN_dup(q), BN_dup(g));
+	DSA_set0_key(ret->mp_dsaKey, BN_dup(pub_key), BN_dup(priv_key));
 
 	return ret;
 

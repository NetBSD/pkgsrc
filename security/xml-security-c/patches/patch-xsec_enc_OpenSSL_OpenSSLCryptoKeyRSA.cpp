$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoKeyRSA.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.cpp
@@ -326,13 +326,15 @@ XSECCryptoKey::KeyType OpenSSLCryptoKeyR
 	if (mp_rsaKey == NULL)
 		return KEY_NONE;
 
-	if (mp_rsaKey->n != NULL && mp_rsaKey->d != NULL)
+	const BIGNUM *n = 0, *e = 0, *d = 0;
+	RSA_get0_key(mp_rsaKey, &n, &e, &d);
+	if (n != NULL && d != NULL)
 		return KEY_RSA_PAIR;
 
-	if (mp_rsaKey->d != NULL)
+	if (d != NULL)
 		return KEY_RSA_PRIVATE;
 
-	if (mp_rsaKey->n != NULL)
+	if (n != NULL)
 		return KEY_RSA_PUBLIC;
 
 	return KEY_NONE;
@@ -344,7 +346,7 @@ void OpenSSLCryptoKeyRSA::loadPublicModu
 	if (mp_rsaKey == NULL)
 		mp_rsaKey = RSA_new();
 
-	mp_rsaKey->n = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	RSA_set0_key(mp_rsaKey, OpenSSLCryptoBase64::b642BN((char *) b64, len), 0, 0);
 
 }
 
@@ -353,7 +355,7 @@ void OpenSSLCryptoKeyRSA::loadPublicExpo
 	if (mp_rsaKey == NULL)
 		mp_rsaKey = RSA_new();
 
-	mp_rsaKey->e = OpenSSLCryptoBase64::b642BN((char *) b64, len);
+	RSA_set0_key(mp_rsaKey, 0, OpenSSLCryptoBase64::b642BN((char *) b64, len), 0);
 
 }
 
@@ -369,32 +371,17 @@ OpenSSLCryptoKeyRSA::OpenSSLCryptoKeyRSA
 
 	mp_rsaKey = RSA_new();
 
-	if (k == NULL || k->type != EVP_PKEY_RSA)
+	if (k == NULL || EVP_PKEY_base_id(k) != EVP_PKEY_RSA)
 		return;	// Nothing to do with us
 
-	if (k->pkey.rsa->n)
-		mp_rsaKey->n = BN_dup(k->pkey.rsa->n);
-
-	if (k->pkey.rsa->e)
-		mp_rsaKey->e = BN_dup(k->pkey.rsa->e);
-
-	if (k->pkey.rsa->d)
-		mp_rsaKey->d = BN_dup(k->pkey.rsa->d);
-
-	if (k->pkey.rsa->p)
-		mp_rsaKey->p = BN_dup(k->pkey.rsa->p);
-
-	if (k->pkey.rsa->q)
-		mp_rsaKey->q = BN_dup(k->pkey.rsa->q);
-
-	if (k->pkey.rsa->dmp1)
-		mp_rsaKey->dmp1 = BN_dup(k->pkey.rsa->dmp1);
-
-	if (k->pkey.rsa->dmq1)
-		mp_rsaKey->dmq1 = BN_dup(k->pkey.rsa->dmq1);
-
-	if (k->pkey.rsa->iqmp)
-		mp_rsaKey->iqmp = BN_dup(k->pkey.rsa->iqmp);
+	RSA *rsa = EVP_PKEY_get0_RSA(k);
+	const BIGNUM *n = 0, *e = 0, *d = 0, *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
+	RSA_get0_key(rsa, &n, &e, &d);
+	RSA_get0_factors(rsa, &p, &q);
+	RSA_get0_crt_params(rsa, &dmp1, &dmq1, &iqmp);
+	RSA_set0_key(mp_rsaKey, BN_dup(n), BN_dup(e), BN_dup(d));
+	RSA_set0_factors(mp_rsaKey, BN_dup(p), BN_dup(q));
+	RSA_set0_crt_params(mp_rsaKey, BN_dup(dmp1), BN_dup(dmq1), BN_dup(iqmp));
 
 }
 
@@ -427,9 +414,9 @@ bool OpenSSLCryptoKeyRSA::verifySHA1PKCS
 	unsigned char* sigVal = new unsigned char[sigLen + 1];
     ArrayJanitor<unsigned char> j_sigVal(sigVal);
 
-    EVP_ENCODE_CTX m_dctx;
-	EVP_DecodeInit(&m_dctx);
-	int rc = EVP_DecodeUpdate(&m_dctx,
+    EVP_ENCODE_CTX *m_dctx = EVP_ENCODE_CTX_new();
+	EVP_DecodeInit(m_dctx);
+	int rc = EVP_DecodeUpdate(m_dctx,
 						  sigVal,
 						  &sigValLen,
 						  (unsigned char *) cleanedBase64Signature,
@@ -442,7 +429,8 @@ bool OpenSSLCryptoKeyRSA::verifySHA1PKCS
 	}
 	int t = 0;
 
-	EVP_DecodeFinal(&m_dctx, &sigVal[sigValLen], &t);
+	EVP_DecodeFinal(m_dctx, &sigVal[sigValLen], &t);
+	EVP_ENCODE_CTX_free(m_dctx);
 
 	sigValLen += t;
 
@@ -979,29 +967,13 @@ XSECCryptoKey * OpenSSLCryptoKeyRSA::clo
 
 	// Duplicate parameters
 
-	if (mp_rsaKey->n)
-		ret->mp_rsaKey->n = BN_dup(mp_rsaKey->n);
-
-	if (mp_rsaKey->e)
-		ret->mp_rsaKey->e = BN_dup(mp_rsaKey->e);
-
-	if (mp_rsaKey->d)
-		ret->mp_rsaKey->d = BN_dup(mp_rsaKey->d);
-
-	if (mp_rsaKey->p)
-		ret->mp_rsaKey->p = BN_dup(mp_rsaKey->p);
-
-	if (mp_rsaKey->q)
-		ret->mp_rsaKey->q = BN_dup(mp_rsaKey->q);
-
-	if (mp_rsaKey->dmp1)
-		ret->mp_rsaKey->dmp1 = BN_dup(mp_rsaKey->dmp1);
-
-	if (mp_rsaKey->dmq1)
-		ret->mp_rsaKey->dmq1 = BN_dup(mp_rsaKey->dmq1);
-
-	if (mp_rsaKey->iqmp)
-		ret->mp_rsaKey->iqmp = BN_dup(mp_rsaKey->iqmp);
+	const BIGNUM *n = 0, *e = 0, *d = 0, *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
+	RSA_get0_key(mp_rsaKey, &n, &e, &d);
+	RSA_get0_factors(mp_rsaKey, &p, &q);
+	RSA_get0_crt_params(mp_rsaKey, &dmp1, &dmq1, &iqmp);
+	RSA_set0_key(ret->mp_rsaKey, BN_dup(n), BN_dup(e), BN_dup(d));
+	RSA_set0_factors(ret->mp_rsaKey, BN_dup(p), BN_dup(q));
+	RSA_set0_crt_params(ret->mp_rsaKey, BN_dup(dmp1), BN_dup(dmq1), BN_dup(iqmp));
 
 	return ret;
 

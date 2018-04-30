$NetBSD: patch-xsec_tools_xklient_xklient.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/tools/xklient/xklient.cpp.orig	2012-07-23 16:56:10.000000000 +0000
+++ xsec/tools/xklient/xklient.cpp
@@ -284,7 +284,7 @@ XSECCryptoX509 * loadX509(const char * i
 
 #if defined (XSEC_HAVE_OPENSSL)
 
-XMLCh * BN2b64(BIGNUM * bn) {
+XMLCh * BN2b64(const BIGNUM * bn) {
 
 	int bytes = BN_num_bytes(bn);
 	unsigned char * binbuf = new unsigned char[bytes + 1];
@@ -606,7 +606,7 @@ XKMSMessageAbstractType * createLocateRe
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -615,10 +615,14 @@ XKMSMessageAbstractType * createLocateRe
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -628,15 +632,18 @@ XKMSMessageAbstractType * createLocateRe
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = lr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -878,7 +885,7 @@ XKMSMessageAbstractType * createValidate
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -887,10 +894,14 @@ XKMSMessageAbstractType * createValidate
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -900,15 +911,18 @@ XKMSMessageAbstractType * createValidate
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = vr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -1229,7 +1243,7 @@ XKMSMessageAbstractType * createRegister
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -1238,10 +1252,14 @@ XKMSMessageAbstractType * createRegister
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -1251,15 +1269,18 @@ XKMSMessageAbstractType * createRegister
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = rr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -1326,7 +1347,7 @@ XKMSMessageAbstractType * createRegister
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -1334,10 +1355,14 @@ XKMSMessageAbstractType * createRegister
 				proofOfPossessionKey = new OpenSSLCryptoKeyDSA(pkey);
 				proofOfPossessionSm = SIGNATURE_DSA;
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				pkb->appendDSAKeyValue(P,Q,G,Y);
 
@@ -1347,7 +1372,7 @@ XKMSMessageAbstractType * createRegister
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
@@ -1355,8 +1380,11 @@ XKMSMessageAbstractType * createRegister
 				proofOfPossessionKey = new OpenSSLCryptoKeyRSA(pkey);
 				proofOfPossessionSm = SIGNATURE_RSA;
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				pkb->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -1622,7 +1650,7 @@ XKMSMessageAbstractType * createRevokeRe
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -1631,10 +1659,14 @@ XKMSMessageAbstractType * createRevokeRe
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -1644,15 +1676,18 @@ XKMSMessageAbstractType * createRevokeRe
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = rr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -1719,15 +1754,19 @@ XKMSMessageAbstractType * createRevokeRe
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				rkb->appendDSAKeyValue(P,Q,G,Y);
 
@@ -1737,13 +1776,16 @@ XKMSMessageAbstractType * createRevokeRe
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				rkb->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -1977,7 +2019,7 @@ XKMSMessageAbstractType * createReissueR
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -1986,10 +2028,14 @@ XKMSMessageAbstractType * createReissueR
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -1999,15 +2045,18 @@ XKMSMessageAbstractType * createReissueR
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = rr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -2074,7 +2123,7 @@ XKMSMessageAbstractType * createReissueR
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -2082,10 +2131,14 @@ XKMSMessageAbstractType * createReissueR
 				proofOfPossessionKey = new OpenSSLCryptoKeyDSA(pkey);
 				proofOfPossessionSm = SIGNATURE_DSA;
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				pkb->appendDSAKeyValue(P,Q,G,Y);
 
@@ -2095,7 +2148,7 @@ XKMSMessageAbstractType * createReissueR
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
@@ -2103,8 +2156,11 @@ XKMSMessageAbstractType * createReissueR
 				proofOfPossessionKey = new OpenSSLCryptoKeyRSA(pkey);
 				proofOfPossessionSm = SIGNATURE_RSA;
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				pkb->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -2371,7 +2427,7 @@ XKMSMessageAbstractType * createRecoverR
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
@@ -2380,10 +2436,14 @@ XKMSMessageAbstractType * createRecoverR
 				// Create the XSEC OpenSSL interface
 				key = new OpenSSLCryptoKeyDSA(pkey);
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				sig->appendDSAKeyValue(P,Q,G,Y);
 
@@ -2393,15 +2453,18 @@ XKMSMessageAbstractType * createRecoverR
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 				sig = rr->addSignature(CANON_C14N_NOC, SIGNATURE_RSA, HASH_SHA1);
 				key = new OpenSSLCryptoKeyRSA(pkey);
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				sig->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -2468,15 +2531,19 @@ XKMSMessageAbstractType * createRecoverR
 
 				// Check type is correct
 
-				if (pkey->type != EVP_PKEY_DSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_DSA) {
 					cerr << "DSA Key requested, but OpenSSL loaded something else\n";
 					return NULL;
 				}
 
-				XMLCh * P = BN2b64(pkey->pkey.dsa->p);
-				XMLCh * Q = BN2b64(pkey->pkey.dsa->q);
-				XMLCh * G = BN2b64(pkey->pkey.dsa->g);
-				XMLCh * Y = BN2b64(pkey->pkey.dsa->pub_key);
+				DSA *dsa = EVP_PKEY_get0_DSA(pkey);
+				const BIGNUM *p, *q, *g, *pub_key;
+				DSA_get0_pqg(dsa, &p, &q, &g);
+				DSA_get0_key(dsa, &pub_key, 0);
+				XMLCh * P = BN2b64(p);
+				XMLCh * Q = BN2b64(q);
+				XMLCh * G = BN2b64(g);
+				XMLCh * Y = BN2b64(pub_key);
 
 				rkb->appendDSAKeyValue(P,Q,G,Y);
 
@@ -2486,13 +2553,16 @@ XKMSMessageAbstractType * createRecoverR
 				XSEC_RELEASE_XMLCH(Y);
 			}
 			else {
-				if (pkey->type != EVP_PKEY_RSA) {
+				if (EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "RSA Key requested, but OpenSSL loaded something else\n";
 					exit (1);
 				}
 
-				XMLCh * mod = BN2b64(pkey->pkey.rsa->n);
-				XMLCh * exp = BN2b64(pkey->pkey.rsa->e);
+				RSA *rsa = EVP_PKEY_get0_RSA(pkey);
+				const BIGNUM *n, *e;
+				RSA_get0_key(rsa, &n, &e, 0);
+				XMLCh * mod = BN2b64(n);
+				XMLCh * exp = BN2b64(e);
 				rkb->appendRSAKeyValue(mod, exp);
 				XSEC_RELEASE_XMLCH(mod);
 				XSEC_RELEASE_XMLCH(exp);
@@ -3251,14 +3321,17 @@ int doRegisterResultDump(XKMSRegisterRes
 
 				// Create the RSA key file
 				RSA * rsa = RSA_new();
-				rsa->n = OpenSSLCryptoBase64::b642BN(sModulus, (unsigned int) strlen(sModulus));
-				rsa->e = OpenSSLCryptoBase64::b642BN(sExponent, (unsigned int) strlen(sExponent));
-				rsa->d = OpenSSLCryptoBase64::b642BN(sD, (unsigned int) strlen(sD));
-				rsa->p = OpenSSLCryptoBase64::b642BN(sP, (unsigned int) strlen(sP));
-				rsa->q = OpenSSLCryptoBase64::b642BN(sQ, (unsigned int) strlen(sQ));
-				rsa->dmp1 = OpenSSLCryptoBase64::b642BN(sDP, (unsigned int) strlen(sDP));
-				rsa->dmq1 = OpenSSLCryptoBase64::b642BN(sDQ, (unsigned int) strlen(sDQ));
-				rsa->iqmp = OpenSSLCryptoBase64::b642BN(sInverseQ, (unsigned int) strlen(sInverseQ));
+				RSA_set0_key(rsa,
+					OpenSSLCryptoBase64::b642BN(sModulus, (unsigned int) strlen(sModulus)),
+					OpenSSLCryptoBase64::b642BN(sExponent, (unsigned int) strlen(sExponent)),
+					OpenSSLCryptoBase64::b642BN(sD, (unsigned int) strlen(sD)));
+				RSA_set0_factors(rsa,
+					OpenSSLCryptoBase64::b642BN(sP, (unsigned int) strlen(sP)),
+					OpenSSLCryptoBase64::b642BN(sQ, (unsigned int) strlen(sQ)));
+				RSA_set0_crt_params(rsa,
+					OpenSSLCryptoBase64::b642BN(sDP, (unsigned int) strlen(sDP)),
+					OpenSSLCryptoBase64::b642BN(sDQ, (unsigned int) strlen(sDQ)),
+					OpenSSLCryptoBase64::b642BN(sInverseQ, (unsigned int) strlen(sInverseQ)));
 
 				// Write it to disk
 				BIO *out;
@@ -3367,14 +3440,17 @@ int doRecoverResultDump(XKMSRecoverResul
 
 				// Create the RSA key file
 				RSA * rsa = RSA_new();
-				rsa->n = OpenSSLCryptoBase64::b642BN(sModulus, (unsigned int) strlen(sModulus));
-				rsa->e = OpenSSLCryptoBase64::b642BN(sExponent, (unsigned int) strlen(sExponent));
-				rsa->d = OpenSSLCryptoBase64::b642BN(sD, (unsigned int) strlen(sD));
-				rsa->p = OpenSSLCryptoBase64::b642BN(sP, (unsigned int) strlen(sP));
-				rsa->q = OpenSSLCryptoBase64::b642BN(sQ, (unsigned int) strlen(sQ));
-				rsa->dmp1 = OpenSSLCryptoBase64::b642BN(sDP, (unsigned int) strlen(sDP));
-				rsa->dmq1 = OpenSSLCryptoBase64::b642BN(sDQ, (unsigned int) strlen(sDQ));
-				rsa->iqmp = OpenSSLCryptoBase64::b642BN(sInverseQ, (unsigned int) strlen(sInverseQ));
+				RSA_set0_key(rsa,
+					OpenSSLCryptoBase64::b642BN(sModulus, (unsigned int) strlen(sModulus)),
+					OpenSSLCryptoBase64::b642BN(sExponent, (unsigned int) strlen(sExponent)),
+					OpenSSLCryptoBase64::b642BN(sD, (unsigned int) strlen(sD)));
+				RSA_set0_factors(rsa,
+					OpenSSLCryptoBase64::b642BN(sP, (unsigned int) strlen(sP)),
+					OpenSSLCryptoBase64::b642BN(sQ, (unsigned int) strlen(sQ)));
+				RSA_set0_crt_params(rsa,
+					OpenSSLCryptoBase64::b642BN(sDP, (unsigned int) strlen(sDP)),
+					OpenSSLCryptoBase64::b642BN(sDQ, (unsigned int) strlen(sDQ)),
+					OpenSSLCryptoBase64::b642BN(sInverseQ, (unsigned int) strlen(sInverseQ)));
 
 				// Write it to disk
 				BIO *out;

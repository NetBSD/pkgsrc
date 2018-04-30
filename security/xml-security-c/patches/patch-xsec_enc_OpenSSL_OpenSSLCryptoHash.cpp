$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoHash.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoHash.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoHash.cpp
@@ -40,6 +40,7 @@
 
 OpenSSLCryptoHash::OpenSSLCryptoHash(HashType alg) {
 
+	m_mdctx = EVP_MD_CTX_create();
 	switch (alg) {
 
 	case (XSECCryptoHash::HASH_SHA1) :
@@ -104,7 +105,7 @@ OpenSSLCryptoHash::OpenSSLCryptoHash(Has
 			"OpenSSL:Hash - Error loading Message Digest"); 
 	}
 
-	EVP_DigestInit(&m_mdctx, mp_md);
+	EVP_DigestInit(m_mdctx, mp_md);
 	m_hashType = alg;
 
 }
@@ -112,7 +113,7 @@ OpenSSLCryptoHash::OpenSSLCryptoHash(Has
 
 OpenSSLCryptoHash::~OpenSSLCryptoHash() {
 
-	EVP_MD_CTX_cleanup(&m_mdctx);
+	EVP_MD_CTX_free(m_mdctx);
 
 }
 
@@ -121,16 +122,16 @@ OpenSSLCryptoHash::~OpenSSLCryptoHash() 
 // Hashing Activities
 void OpenSSLCryptoHash::reset(void) {
 
-	EVP_MD_CTX_cleanup(&m_mdctx);
-
-	EVP_DigestInit(&m_mdctx, mp_md);
+	EVP_MD_CTX_free(m_mdctx);
+	m_mdctx = EVP_MD_CTX_new();
+	EVP_DigestInit(m_mdctx, mp_md);
 
 }
 
 void OpenSSLCryptoHash::hash(unsigned char * data, 
 								 unsigned int length) {
 
-	EVP_DigestUpdate(&m_mdctx, data, length);
+	EVP_DigestUpdate(m_mdctx, data, length);
 
 }
 unsigned int OpenSSLCryptoHash::finish(unsigned char * hash,
@@ -140,7 +141,7 @@ unsigned int OpenSSLCryptoHash::finish(u
 
 	// Finish up and copy out hash, returning the length
 
-	EVP_DigestFinal(&m_mdctx, m_mdValue, &m_mdLen);
+	EVP_DigestFinal(m_mdctx, m_mdValue, &m_mdLen);
 
 	// Copy to output buffer
 	

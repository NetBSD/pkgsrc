$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoHashHMAC.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.cpp
@@ -43,6 +43,7 @@
 OpenSSLCryptoHashHMAC::OpenSSLCryptoHashHMAC(HashType alg) {
 
 	// Initialise the digest
+	m_hctx = HMAC_CTX_new();
 
 	switch (alg) {
 
@@ -127,7 +128,7 @@ void OpenSSLCryptoHashHMAC::setKey(XSECC
 	m_keyLen = ((XSECCryptoKeyHMAC *) key)->getKey(m_keyBuf);
 
 
-	HMAC_Init(&m_hctx, 
+	HMAC_Init(m_hctx, 
 		m_keyBuf.rawBuffer(),
 		m_keyLen,
 		mp_md);
@@ -139,7 +140,7 @@ void OpenSSLCryptoHashHMAC::setKey(XSECC
 OpenSSLCryptoHashHMAC::~OpenSSLCryptoHashHMAC() {
 
 	if (m_initialised)
-		HMAC_CTX_cleanup(&m_hctx);
+		HMAC_CTX_free(m_hctx);
 
 }
 
@@ -151,9 +152,9 @@ void OpenSSLCryptoHashHMAC::reset(void) 
 
 	if (m_initialised) {
 
-		HMAC_CTX_cleanup(&m_hctx);
-
-		HMAC_Init(&m_hctx, 
+		HMAC_CTX_free(m_hctx);
+		m_hctx = HMAC_CTX_new();
+		HMAC_Init(m_hctx, 
 			m_keyBuf.rawBuffer(),
 			m_keyLen,
 			mp_md);
@@ -170,7 +171,7 @@ void OpenSSLCryptoHashHMAC::hash(unsigne
 			"OpenSSL:HashHMAC - hash called prior to setKey");
 
 
-	HMAC_Update(&m_hctx, data, (int) length);
+	HMAC_Update(m_hctx, data, (int) length);
 
 }
 
@@ -181,7 +182,7 @@ unsigned int OpenSSLCryptoHashHMAC::fini
 
 	// Finish up and copy out hash, returning the length
 
-	HMAC_Final(&m_hctx, m_mdValue, &m_mdLen);
+	HMAC_Final(m_hctx, m_mdValue, &m_mdLen);
 
 	// Copy to output buffer
 	

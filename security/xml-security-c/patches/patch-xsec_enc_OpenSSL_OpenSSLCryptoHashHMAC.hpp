$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoHashHMAC.hpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.hpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoHashHMAC.hpp
@@ -162,7 +162,7 @@ public :
 	 * \brief Get OpenSSL Hash Context
 	 */
 
-	HMAC_CTX * getOpenSSLHMAC_CTX(void) {return &m_hctx;}
+	HMAC_CTX * getOpenSSLHMAC_CTX(void) {return m_hctx;}
 
 	//@}
 
@@ -175,7 +175,7 @@ private:
 	unsigned char		m_mdValue[EVP_MAX_MD_SIZE];		// Final output
 	unsigned int		m_mdLen;						// Length of digest
 	HashType			m_hashType;						// What type of hash is this?
-	HMAC_CTX			m_hctx;							// Context for HMAC
+	HMAC_CTX			*m_hctx;							// Context for HMAC
 	safeBuffer			m_keyBuf;						// The loaded key
 	unsigned int		m_keyLen;						// The loaded key length
 	bool				m_initialised;

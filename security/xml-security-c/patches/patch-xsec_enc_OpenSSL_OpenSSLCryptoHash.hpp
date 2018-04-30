$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoHash.hpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoHash.hpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoHash.hpp
@@ -138,7 +138,7 @@ public :
 	 * \brief Get OpenSSL hash context structure
 	 */
 
-	EVP_MD_CTX * getOpenSSLEVP_MD_CTX(void) {return &m_mdctx;}
+	EVP_MD_CTX * getOpenSSLEVP_MD_CTX(void) {return m_mdctx;}
 
 	//@}
 
@@ -148,7 +148,7 @@ private:
 	// Not implemented constructors
 	OpenSSLCryptoHash();
 
-	EVP_MD_CTX			m_mdctx;						// Context for digest
+	EVP_MD_CTX			*m_mdctx;						// Context for digest
 	const EVP_MD		* mp_md;						// Digest instance
 	unsigned char		m_mdValue[EVP_MAX_MD_SIZE];		// Final output
 	unsigned int		m_mdLen;						// Length of digest

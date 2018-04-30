$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoSymmetricKey.hpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.hpp
@@ -283,13 +283,13 @@ public :
 	 * \brief Get OpenSSL cipher context structure
 	 */
 
-	EVP_CIPHER_CTX * getOpenSSLEVP_CIPHER_CTX(void) {return &m_ctx;}
+	EVP_CIPHER_CTX * getOpenSSLEVP_CIPHER_CTX(void) {return m_ctx;}
 
     /**
 	 * \brief Get OpenSSL cipher context structure
 	 */
 
-	const EVP_CIPHER_CTX * getOpenSSLEVP_CIPHER_CTX(void) const {return &m_ctx;}
+	const EVP_CIPHER_CTX * getOpenSSLEVP_CIPHER_CTX(void) const {return m_ctx;}
 
 	//@}
 
@@ -307,7 +307,7 @@ private:
 	// Private variables
 	SymmetricKeyType				m_keyType;
 	SymmetricKeyMode				m_keyMode;
-	EVP_CIPHER_CTX					m_ctx;			// OpenSSL Cipher Context structure
+	EVP_CIPHER_CTX					*m_ctx;			// OpenSSL Cipher Context structure
 	safeBuffer						m_keyBuf;		// Holder of the key
     safeBuffer                      m_tagBuf;       // Holder of authentication tag
 	unsigned int					m_keyLen;

$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoBase64.hpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoBase64.hpp
@@ -66,8 +66,8 @@ class DSIG_EXPORT OpenSSLCryptoBase64 : 
 public :
 
 	
-	OpenSSLCryptoBase64() {};
-	virtual ~OpenSSLCryptoBase64() {};
+	OpenSSLCryptoBase64();
+	virtual ~OpenSSLCryptoBase64();
 
 	/** @name Decoding Functions */
 	//@{
@@ -189,20 +189,20 @@ public :
 	 * \brief Get OpenSSL encode context structure
 	 */
 
-	EVP_ENCODE_CTX * getOpenSSLEncodeEVP_ENCODE_CTX(void) {return &m_ectx;}
+	EVP_ENCODE_CTX * getOpenSSLEncodeEVP_ENCODE_CTX(void) {return m_ectx;}
 
 	/**
 	 * \brief Get OpenSSL encode context structure
 	 */
 
-	EVP_ENCODE_CTX * getOpenSSLDecodeEVP_ENCODE_CTX(void) {return &m_dctx;}
+	EVP_ENCODE_CTX * getOpenSSLDecodeEVP_ENCODE_CTX(void) {return m_dctx;}
 
 	//@}
 
 private :
 
-	EVP_ENCODE_CTX m_ectx;				// Encode context
-	EVP_ENCODE_CTX m_dctx;				// Decode context
+	EVP_ENCODE_CTX *m_ectx;				// Encode context
+	EVP_ENCODE_CTX *m_dctx;				// Decode context
 
 };
 

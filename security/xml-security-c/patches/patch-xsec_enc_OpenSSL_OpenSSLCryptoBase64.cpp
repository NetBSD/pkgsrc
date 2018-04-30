$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoBase64.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoBase64.cpp
@@ -44,6 +44,15 @@
 
 XERCES_CPP_NAMESPACE_USE
 
+OpenSSLCryptoBase64::OpenSSLCryptoBase64() {
+	m_ectx = EVP_ENCODE_CTX_new();
+	m_dctx = EVP_ENCODE_CTX_new();
+}
+
+OpenSSLCryptoBase64::~OpenSSLCryptoBase64() {
+	EVP_ENCODE_CTX_free(m_ectx);
+	EVP_ENCODE_CTX_free(m_dctx);
+}
 
 // --------------------------------------------------------------------------------
 //           Decoding
@@ -51,7 +60,7 @@ XERCES_CPP_NAMESPACE_USE
 
 void OpenSSLCryptoBase64::decodeInit(void) {
 
-	EVP_DecodeInit(&m_dctx);
+	EVP_DecodeInit(m_dctx);
 
 }
 
@@ -70,7 +79,7 @@ unsigned int OpenSSLCryptoBase64::decode
 
 	}
 
-	rc = EVP_DecodeUpdate(&m_dctx, 
+	rc = EVP_DecodeUpdate(m_dctx, 
 						  outData, 
 						  &outLen, 
 						  (unsigned char *) inData, 
@@ -99,7 +108,7 @@ unsigned int OpenSSLCryptoBase64::decode
 	int outLen;
 	outLen = outLength;
 
-	EVP_DecodeFinal(&m_dctx, outData, &outLen); 
+	EVP_DecodeFinal(m_dctx, outData, &outLen); 
 
 	return outLen;
 
@@ -111,7 +120,7 @@ unsigned int OpenSSLCryptoBase64::decode
 
 void OpenSSLCryptoBase64::encodeInit(void) {
 
-	EVP_EncodeInit(&m_ectx);
+	EVP_EncodeInit(m_ectx);
 
 }
 
@@ -130,7 +139,7 @@ unsigned int OpenSSLCryptoBase64::encode
 
 	}
 
-	EVP_EncodeUpdate(&m_ectx, 
+	EVP_EncodeUpdate(m_ectx, 
 					  outData, 
 					  &outLen, 
 					  (unsigned char *) inData, 
@@ -153,7 +162,7 @@ unsigned int OpenSSLCryptoBase64::encode
 	int outLen;
 	outLen = outLength;
 
-	EVP_EncodeFinal(&m_ectx, outData, &outLen); 
+	EVP_EncodeFinal(m_ectx, outData, &outLen); 
 
 	return outLen;
 

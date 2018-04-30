$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoSymmetricKey.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp.orig	2015-01-29 02:52:17.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoSymmetricKey.cpp
@@ -56,7 +56,8 @@ m_tagBuf(""),
 m_keyLen(0),
 m_initialised(false) {
 
-	EVP_CIPHER_CTX_init(&m_ctx);
+	m_ctx = EVP_CIPHER_CTX_new();
+	EVP_CIPHER_CTX_init(m_ctx);
 	m_keyBuf.isSensitive();
 
 }
@@ -65,7 +66,7 @@ OpenSSLCryptoSymmetricKey::~OpenSSLCrypt
 
 	// Clean up the context
 
-	EVP_CIPHER_CTX_cleanup(&m_ctx);
+	EVP_CIPHER_CTX_free(m_ctx);
 }
 
 // --------------------------------------------------------------------------------
@@ -149,17 +150,17 @@ int OpenSSLCryptoSymmetricKey::decryptCt
 			   with 0.9.6 */
 
 #if defined(XSEC_OPENSSL_CONST_BUFFERS)
-			EVP_DecryptInit(&m_ctx, EVP_des_ede3_cbc(),m_keyBuf.rawBuffer(), iv);
+			EVP_DecryptInit(m_ctx, EVP_des_ede3_cbc(),m_keyBuf.rawBuffer(), iv);
 #else
-			EVP_DecryptInit(&m_ctx, EVP_des_ede3_cbc(),(unsigned char *) m_keyBuf.rawBuffer(), (unsigned char *) iv);
+			EVP_DecryptInit(m_ctx, EVP_des_ede3_cbc(),(unsigned char *) m_keyBuf.rawBuffer(), (unsigned char *) iv);
 #endif
 			m_ivSize = 8;
 		}
 		else if (m_keyMode == MODE_ECB) {
 #if defined(XSEC_OPENSSL_CONST_BUFFERS)
-			EVP_DecryptInit(&m_ctx, EVP_des_ecb(), m_keyBuf.rawBuffer(), NULL);
+			EVP_DecryptInit(m_ctx, EVP_des_ecb(), m_keyBuf.rawBuffer(), NULL);
 #else
-			EVP_DecryptInit(&m_ctx, EVP_des_ecb(), (unsigned char *) m_keyBuf.rawBuffer(), NULL);
+			EVP_DecryptInit(m_ctx, EVP_des_ecb(), (unsigned char *) m_keyBuf.rawBuffer(), NULL);
 #endif
 			m_ivSize = 0;
 		}
@@ -184,7 +185,7 @@ int OpenSSLCryptoSymmetricKey::decryptCt
 				return 0;	// Cannot initialise without an IV
 			}
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_128_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_128_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
 
 		}
 #if defined (XSEC_OPENSSL_HAVE_GCM)
@@ -207,15 +208,15 @@ int OpenSSLCryptoSymmetricKey::decryptCt
             }
 
             // We have everything, so we can fully init.
-            EVP_CipherInit(&m_ctx, EVP_aes_128_gcm(), NULL, NULL, 0);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
-            EVP_CipherInit(&m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
+            EVP_CipherInit(m_ctx, EVP_aes_128_gcm(), NULL, NULL, 0);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
+            EVP_CipherInit(m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
 		}
 #endif
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_128_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_128_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 
 		}
         else {
@@ -236,7 +237,7 @@ int OpenSSLCryptoSymmetricKey::decryptCt
 				return 0;	// Cannot initialise without an IV
 			}
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_192_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_192_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
 
 		}
 #if defined (XSEC_OPENSSL_HAVE_GCM)
@@ -259,16 +260,16 @@ int OpenSSLCryptoSymmetricKey::decryptCt
             }
 
             // We have everything, so we can fully init.
-            EVP_CipherInit(&m_ctx, EVP_aes_192_gcm(), NULL, NULL, 0);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
-            EVP_CipherInit(&m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
+            EVP_CipherInit(m_ctx, EVP_aes_192_gcm(), NULL, NULL, 0);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
+            EVP_CipherInit(m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
 
 		}
 #endif
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_192_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_192_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 
 		}
         else {
@@ -289,7 +290,7 @@ int OpenSSLCryptoSymmetricKey::decryptCt
 				return 0;	// Cannot initialise without an IV
 			}
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_256_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_256_cbc(), NULL, m_keyBuf.rawBuffer(), iv);
 
 		}
 #if defined (XSEC_OPENSSL_HAVE_GCM)
@@ -312,16 +313,16 @@ int OpenSSLCryptoSymmetricKey::decryptCt
             }
 
             // We have everything, so we can fully init.
-            EVP_CipherInit(&m_ctx, EVP_aes_256_gcm(), NULL, NULL, 0);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
-            EVP_CipherInit(&m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
+            EVP_CipherInit(m_ctx, EVP_aes_256_gcm(), NULL, NULL, 0);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_SET_TAG, 16, (void*)m_tagBuf.rawBuffer());
+            EVP_CipherInit(m_ctx, NULL, m_keyBuf.rawBuffer(), iv, 0);
 
 		}
 #endif
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_DecryptInit_ex(&m_ctx, EVP_aes_256_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_DecryptInit_ex(m_ctx, EVP_aes_256_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 
 		}
         else {
@@ -371,7 +372,7 @@ int OpenSSLCryptoSymmetricKey::decryptCt
 	// Disable OpenSSL padding - The interop samples have broken PKCS padding - AARGHH
 
 #if defined (XSEC_OPENSSL_CANSET_PADDING)
-	EVP_CIPHER_CTX_set_padding(&m_ctx, 0);
+	EVP_CIPHER_CTX_set_padding(m_ctx, 0);
 #endif
 
 	// Return number of bytes chewed up by IV
@@ -439,9 +440,9 @@ unsigned int OpenSSLCryptoSymmetricKey::
 	}
 
 #if defined (XSEC_OPENSSL_CONST_BUFFERS)
-	if (EVP_DecryptUpdate(&m_ctx, &plainBuf[m_bytesInLastBlock], &outl, &inBuf[offset], inLength - offset) == 0) {
+	if (EVP_DecryptUpdate(m_ctx, &plainBuf[m_bytesInLastBlock], &outl, &inBuf[offset], inLength - offset) == 0) {
 #else
-	if (EVP_DecryptUpdate(&m_ctx, &plainBuf[m_bytesInLastBlock], &outl, (unsigned char *) &inBuf[offset], inLength - offset) == 0) {
+	if (EVP_DecryptUpdate(m_ctx, &plainBuf[m_bytesInLastBlock], &outl, (unsigned char *) &inBuf[offset], inLength - offset) == 0) {
 #endif
 		throw XSECCryptoException(XSECCryptoException::SymmetricError,
 			"OpenSSL:SymmetricKey - Error during OpenSSL decrypt"); 
@@ -476,7 +477,7 @@ unsigned int OpenSSLCryptoSymmetricKey::
 
 #if defined (XSEC_OPENSSL_CANSET_PADDING)
 
-	if (EVP_DecryptFinal(&m_ctx, plainBuf, &outl) == 0) {
+	if (EVP_DecryptFinal(m_ctx, plainBuf, &outl) == 0) {
 
 		throw XSECCryptoException(XSECCryptoException::SymmetricError,
 			"OpenSSL:SymmetricKey - Error during OpenSSL decrypt finalisation"); 
@@ -544,7 +545,7 @@ unsigned int OpenSSLCryptoSymmetricKey::
        We can then clean that up ourselves
 	*/
 
-	if (EVP_DecryptUpdate(&m_ctx, &scrPlainBuf[offset], &outl, cipherBuf, m_blockSize) == 0) {
+	if (EVP_DecryptUpdate(m_ctx, &scrPlainBuf[offset], &outl, cipherBuf, m_blockSize) == 0) {
 		throw XSECCryptoException(XSECCryptoException::SymmetricError,
 			"OpenSSL:SymmetricKey - Error cecrypting final block during OpenSSL");
 	} 
@@ -641,16 +642,16 @@ bool OpenSSLCryptoSymmetricKey::encryptI
             }
 
 #if defined (XSEC_OPENSSL_CONST_BUFFERS)
-			EVP_EncryptInit(&m_ctx, EVP_des_ede3_cbc(), m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit(m_ctx, EVP_des_ede3_cbc(), m_keyBuf.rawBuffer(), usedIV);
 #else
-			EVP_EncryptInit(&m_ctx, EVP_des_ede3_cbc(), (unsigned char *) m_keyBuf.rawBuffer(), (unsigned char *) usedIV);
+			EVP_EncryptInit(m_ctx, EVP_des_ede3_cbc(), (unsigned char *) m_keyBuf.rawBuffer(), (unsigned char *) usedIV);
 #endif
 		}
 		else if (m_keyMode == MODE_ECB) {
 #if defined (XSEC_OPENSSL_CONST_BUFFERS)
-			EVP_EncryptInit(&m_ctx, EVP_des_ede3_ecb(), m_keyBuf.rawBuffer(), NULL);
+			EVP_EncryptInit(m_ctx, EVP_des_ede3_ecb(), m_keyBuf.rawBuffer(), NULL);
 #else
-			EVP_EncryptInit(&m_ctx, EVP_des_ede3(), (unsigned char *) m_keyBuf.rawBuffer(), NULL);
+			EVP_EncryptInit(m_ctx, EVP_des_ede3(), (unsigned char *) m_keyBuf.rawBuffer(), NULL);
 #endif
 		}
         else {
@@ -684,11 +685,11 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_128_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_128_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
 		}
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_128_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_128_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 
 		}
 #ifdef XSEC_OPENSSL_HAVE_GCM
@@ -708,7 +709,7 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_128_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_128_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
 		}
 #endif
         else {
@@ -739,7 +740,7 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_192_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_192_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
 
 		}
 #ifdef XSEC_OPENSSL_HAVE_GCM
@@ -759,12 +760,12 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_192_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_192_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
 		}
 #endif
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_192_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_192_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 		}
         else {
 		    throw XSECCryptoException(XSECCryptoException::SymmetricError,
@@ -793,7 +794,7 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_256_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_256_cbc(), NULL, m_keyBuf.rawBuffer(), usedIV);
 
 		}
 #ifdef XSEC_OPENSSL_HAVE_GCM
@@ -813,12 +814,12 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 			else
 				usedIV = iv;
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_256_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_256_gcm(), NULL, m_keyBuf.rawBuffer(), usedIV);
 		}
 #endif
 		else if (m_keyMode == MODE_ECB) {
 
-			EVP_EncryptInit_ex(&m_ctx, EVP_aes_256_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
+			EVP_EncryptInit_ex(m_ctx, EVP_aes_256_ecb(), NULL, m_keyBuf.rawBuffer(), NULL);
 
 		}
         else {
@@ -864,10 +865,10 @@ bool OpenSSLCryptoSymmetricKey::encryptI
 #if defined (XSEC_OPENSSL_CANSET_PADDING)
 	// Setup padding
 	if (m_doPad) {
-		EVP_CIPHER_CTX_set_padding(&m_ctx, 1);
+		EVP_CIPHER_CTX_set_padding(m_ctx, 1);
 	}
 	else {
-		EVP_CIPHER_CTX_set_padding(&m_ctx, 0);
+		EVP_CIPHER_CTX_set_padding(m_ctx, 0);
 	}
 #endif
 
@@ -908,9 +909,9 @@ unsigned int OpenSSLCryptoSymmetricKey::
 
 	}
 #if defined (XSEC_OPENSSL_CONST_BUFFERS)
-	if (EVP_EncryptUpdate(&m_ctx, &cipherBuf[offset], &outl, inBuf, inLength) == 0) {
+	if (EVP_EncryptUpdate(m_ctx, &cipherBuf[offset], &outl, inBuf, inLength) == 0) {
 #else
-	if (EVP_EncryptUpdate(&m_ctx, &cipherBuf[offset], &outl, (unsigned char *) inBuf, inLength) == 0) {
+	if (EVP_EncryptUpdate(m_ctx, &cipherBuf[offset], &outl, (unsigned char *) inBuf, inLength) == 0) {
 #endif
 
 		throw XSECCryptoException(XSECCryptoException::SymmetricError,
@@ -929,7 +930,7 @@ unsigned int OpenSSLCryptoSymmetricKey::
 	int outl = maxOutLength;
 	m_initialised = false;
 
-	if (EVP_EncryptFinal(&m_ctx, cipherBuf, &outl) == 0) {
+	if (EVP_EncryptFinal(m_ctx, cipherBuf, &outl) == 0) {
 
 		throw XSECCryptoException(XSECCryptoException::SymmetricError,
 		  "OpenSSLSymmetricKey::encryptFinish - Error during OpenSSL decrypt finalisation"); 
@@ -962,7 +963,7 @@ unsigned int OpenSSLCryptoSymmetricKey::
         }
         if (m_keyMode == MODE_GCM) {
 #ifdef XSEC_OPENSSL_HAVE_GCM
-            EVP_CIPHER_CTX_ctrl(&m_ctx, EVP_CTRL_GCM_GET_TAG, taglen, cipherBuf + outl);
+            EVP_CIPHER_CTX_ctrl(m_ctx, EVP_CTRL_GCM_GET_TAG, taglen, cipherBuf + outl);
             outl += taglen;
 #else
 		    throw XSECCryptoException(XSECCryptoException::SymmetricError,

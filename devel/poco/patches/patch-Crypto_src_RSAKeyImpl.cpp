$NetBSD: patch-Crypto_src_RSAKeyImpl.cpp,v 1.1 2020/03/27 02:08:11 joerg Exp $

--- Crypto/src/RSAKeyImpl.cpp.orig	2020-03-27 00:20:44.185120322 +0000
+++ Crypto/src/RSAKeyImpl.cpp
@@ -207,19 +207,19 @@ int RSAKeyImpl::size() const
 
 RSAKeyImpl::ByteVec RSAKeyImpl::modulus() const
 {
-	return convertToByteVec(_pRSA->n);
+	return convertToByteVec(RSA_get0_n(_pRSA));
 }
 
 
 RSAKeyImpl::ByteVec RSAKeyImpl::encryptionExponent() const
 {
-	return convertToByteVec(_pRSA->e);
+	return convertToByteVec(RSA_get0_e(_pRSA));
 }
 
 
 RSAKeyImpl::ByteVec RSAKeyImpl::decryptionExponent() const
 {
-	return convertToByteVec(_pRSA->d);
+	return convertToByteVec(RSA_get0_d(_pRSA));
 }
 
 

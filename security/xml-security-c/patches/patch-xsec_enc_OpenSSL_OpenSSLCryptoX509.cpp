$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoX509.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoX509.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoX509.cpp
@@ -191,7 +191,7 @@ XSECCryptoKey::KeyType OpenSSLCryptoX509
 
 	XSECCryptoKey::KeyType ret;
 
-	switch (pkey->type) {
+	switch (EVP_PKEY_base_id(pkey)) {
 
 	case EVP_PKEY_DSA :
 
@@ -241,7 +241,7 @@ XSECCryptoKey * OpenSSLCryptoX509::clone
 			"OpenSSL:X509 - cannot retrieve public key from cert");
 	}
 
-	switch (pkey->type) {
+	switch (EVP_PKEY_base_id(pkey)) {
 
 	case EVP_PKEY_DSA :
 

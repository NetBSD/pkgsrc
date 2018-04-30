$NetBSD: patch-xsec_tools_cipher_cipher.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/tools/cipher/cipher.cpp.orig	2015-01-30 03:55:09.000000000 +0000
+++ xsec/tools/cipher/cipher.cpp
@@ -517,7 +517,7 @@ int evaluate(int argc, char ** argv) {
 
 				pkey = X509_get_pubkey(x);
 
-				if (pkey == NULL || pkey->type != EVP_PKEY_RSA) {
+				if (pkey == NULL || EVP_PKEY_base_id(pkey) != EVP_PKEY_RSA) {
 					cerr << "Error extracting RSA key from certificate" << endl;
 				}
 

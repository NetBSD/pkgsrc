$NetBSD: patch-xsec_enc_OpenSSL_OpenSSLCryptoProvider.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/enc/OpenSSL/OpenSSLCryptoProvider.cpp.orig	2012-07-23 16:56:11.000000000 +0000
+++ xsec/enc/OpenSSL/OpenSSLCryptoProvider.cpp
@@ -343,7 +343,7 @@ XSECCryptoKey* OpenSSLCryptoProvider::ke
     if (pkey) {
         XSECCryptoKey* ret = NULL;
         try {
-            switch (pkey->type) {
+            switch (EVP_PKEY_base_id(pkey)) {
                 case EVP_PKEY_RSA:
                     ret = new OpenSSLCryptoKeyRSA(pkey);
                     break;

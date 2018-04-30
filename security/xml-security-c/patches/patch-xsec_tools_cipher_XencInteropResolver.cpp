$NetBSD: patch-xsec_tools_cipher_XencInteropResolver.cpp,v 1.1 2018/04/30 05:25:24 ryoon Exp $

--- xsec/tools/cipher/XencInteropResolver.cpp.orig	2012-07-23 16:56:10.000000000 +0000
+++ xsec/tools/cipher/XencInteropResolver.cpp
@@ -521,7 +521,7 @@ XSECCryptoKey * XencInteropResolver::res
 					X509 * x509 = OSSLX509->getOpenSSLX509();
 
 					// Check the serial number
-					BIGNUM * bnserial = ASN1_INTEGER_to_BN(x509->cert_info->serialNumber, NULL);
+					BIGNUM * bnserial = ASN1_INTEGER_to_BN(X509_get0_serialNumber(x509), NULL);
 					BN_free(bnserial);
 
 					BIO * rsaFile = createFileBIO(mp_baseURI, "rsa.p8");

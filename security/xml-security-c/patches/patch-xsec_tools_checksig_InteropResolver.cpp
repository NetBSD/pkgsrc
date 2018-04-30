$NetBSD: patch-xsec_tools_checksig_InteropResolver.cpp,v 1.2 2018/04/30 05:25:24 ryoon Exp $

false is a bad pointer value.

--- xsec/tools/checksig/InteropResolver.cpp.orig	2018-04-10 03:53:05.001719015 +0000
+++ xsec/tools/checksig/InteropResolver.cpp
@@ -318,7 +318,7 @@ bool InteropResolver::checkMatch(DSIGKey
 				char * cserial = XMLString::transcode(serial);
 				char * xserial;
 
-				BIGNUM * bnserial = ASN1_INTEGER_to_BN(x->cert_info->serialNumber, NULL);
+				BIGNUM * bnserial = ASN1_INTEGER_to_BN(X509_get0_serialNumber(x), NULL);
 				xserial = BN_bn2dec(bnserial);
 				BN_free(bnserial);
 
@@ -360,8 +360,7 @@ bool InteropResolver::checkMatch(DSIGKey
 				if (xlen != 0) {
 
 					// Have a buffer with a number in it
-					STACK_OF(X509_EXTENSION) *exts;
-					exts = x->cert_info->extensions;
+					const STACK_OF(X509_EXTENSION) *exts = X509_get0_extensions(x);
 
 					if (exts != NULL) {
 
@@ -379,8 +378,8 @@ bool InteropResolver::checkMatch(DSIGKey
 							memcpy(&octxski[2], xski, xlen);
 							
 							ext = sk_X509_EXTENSION_value(exts,extn);
-							ASN1_OCTET_STRING *skid = ext->value;
-							ASN1_OCTET_STRING * xskid = M_ASN1_OCTET_STRING_new();
+							ASN1_OCTET_STRING *skid = X509_EXTENSION_get_data(ext);
+							ASN1_OCTET_STRING * xskid = ASN1_OCTET_STRING_new();
 							ASN1_STRING_set(xskid, octxski, xlen+2);
 							
 							if (ASN1_OCTET_STRING_cmp(xskid, skid) == 0) {
@@ -602,12 +601,12 @@ XSECCryptoKey * InteropResolver::resolve
 		// Now check if the cert is in the CRL (code lifted from OpenSSL x509_vfy.c
 
         int idx;
-        X509_REVOKED rtmp;
+        X509_REVOKED *rtmp = X509_REVOKED_new();
 
         /* Look for serial number of certificate in CRL */
         
-		rtmp.serialNumber = X509_get_serialNumber(x);
-        idx = sk_X509_REVOKED_find(c->crl->revoked, &rtmp);
+		X509_REVOKED_set_serialNumber(rtmp, X509_get_serialNumber(x));
+        idx = sk_X509_REVOKED_find(X509_CRL_get_REVOKED(c), rtmp);
         
 		/* Not found: OK */
         
@@ -645,7 +644,7 @@ XSECCryptoKey * InteropResolver::resolve
 
 	}
 
-	return false;
+	return NULL;
 
 }
 

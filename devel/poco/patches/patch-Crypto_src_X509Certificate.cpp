$NetBSD: patch-Crypto_src_X509Certificate.cpp,v 1.1 2020/03/27 02:08:11 joerg Exp $

--- Crypto/src/X509Certificate.cpp.orig	2020-03-27 00:40:15.548521424 +0000
+++ Crypto/src/X509Certificate.cpp
@@ -59,7 +59,7 @@ X509Certificate::X509Certificate(X509* p
 	
 	if (shared)
 	{
-		_pCert->references++;
+		X509_up_ref(_pCert);
 	}
 
 	init();

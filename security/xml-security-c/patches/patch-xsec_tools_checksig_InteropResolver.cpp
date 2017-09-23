$NetBSD: patch-xsec_tools_checksig_InteropResolver.cpp,v 1.1 2017/09/23 15:30:01 joerg Exp $

false is a bad pointer value.

--- xsec/tools/checksig/InteropResolver.cpp.orig	2017-09-23 12:23:36.663288313 +0000
+++ xsec/tools/checksig/InteropResolver.cpp
@@ -645,7 +645,7 @@ XSECCryptoKey * InteropResolver::resolve
 
 	}
 
-	return false;
+	return NULL;
 
 }
 

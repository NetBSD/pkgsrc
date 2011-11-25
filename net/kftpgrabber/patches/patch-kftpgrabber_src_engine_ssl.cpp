$NetBSD: patch-kftpgrabber_src_engine_ssl.cpp,v 1.1 2011/11/25 22:12:28 joerg Exp $

--- kftpgrabber/src/engine/ssl.cpp.orig	2011-11-25 18:51:58.000000000 +0000
+++ kftpgrabber/src/engine/ssl.cpp
@@ -169,7 +169,7 @@ bool Ssl::setClientCertificate(KSSLPKCS1
 
 void Ssl::setConnectionInfo()
 {
-  SSL_CIPHER *cipher;
+  const SSL_CIPHER *cipher;
   char buffer[1024];
   
   buffer[0] = 0;

$NetBSD: patch-lib_cpp_src_transport_TServerSocket.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/transport/TServerSocket.cpp.orig	2013-05-03 22:05:44.000000000 +0000
+++ lib/cpp/src/transport/TServerSocket.cpp
@@ -268,14 +268,14 @@ void TServerSocket::listen() {
     len = sizeof(address);
 
     do {
-      if (0 == bind(serverSocket_, (struct sockaddr *) &address, len)) {
+      if (0 == ::bind(serverSocket_, (struct sockaddr *) &address, len)) {
         break;
       }
       // use short circuit evaluation here to only sleep if we need to
     } while ((retries++ < retryLimit_) && (sleep(retryDelay_) == 0));
   } else {
     do {
-      if (0 == bind(serverSocket_, res->ai_addr, res->ai_addrlen)) {
+      if (0 == ::bind(serverSocket_, res->ai_addr, res->ai_addrlen)) {
         break;
       }
       // use short circuit evaluation here to only sleep if we need to

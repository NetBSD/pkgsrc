$NetBSD: patch-libs_sockets_tcpsocket.cpp,v 1.1 2024/05/03 11:17:14 wiz Exp $

Add header for sockaddr_in definition.

--- libs/sockets/tcpsocket.cpp.orig	2024-05-03 10:35:05.023675865 +0000
+++ libs/sockets/tcpsocket.cpp
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <chrono>
 #include <algorithm>
+#include <netinet/in.h>
 
 // SocketAddress
 const char *SocketAddress::unixDomainPrefix = "localhost:";

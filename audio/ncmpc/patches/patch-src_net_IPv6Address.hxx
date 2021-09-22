$NetBSD: patch-src_net_IPv6Address.hxx,v 1.1 2021/09/22 06:56:10 nia Exp $

Avoid a compilation problem on netbsd-8:

../src/net/IPv6Address.hxx:192:10: error: 'ntohl' was not declared in this scope
   return IN6_IS_ADDR_V4MAPPED(&address.sin6_addr);

--- src/net/IPv6Address.hxx.orig	2021-02-12 09:53:25.000000000 +0000
+++ src/net/IPv6Address.hxx
@@ -40,6 +40,7 @@
 #include <winsock2.h>
 #include <ws2tcpip.h>
 #else
+#include <arpa/inet.h>
 #include <netinet/in.h>
 #endif
 

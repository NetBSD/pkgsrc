$NetBSD: patch-src_net_IPv6Address.hxx,v 1.3 2022/07/12 20:16:08 triaxx Exp $

Fixes
In file included from /usr/include/netinet/in.h:372:0,
                 from ../src/net/IPv4Address.hxx:42,
                 from ../src/event/ServerSocket.cxx:22:
../src/net/IPv6Address.hxx: In member function 'bool IPv6Address::IsV4Mapped() const':
../src/net/IPv6Address.hxx:175:10: error: 'ntohl' was not declared in this scope
   return IN6_IS_ADDR_V4MAPPED(&address.sin6_addr);
          ^
before this commit:
https://mail-index.netbsd.org/source-changes/2018/12/10/msg101328.html

https://github.com/MusicPlayerDaemon/MPD/issues/438

--- src/net/IPv6Address.hxx.orig	2020-09-23 13:26:51.000000000 +0000
+++ src/net/IPv6Address.hxx
@@ -40,6 +40,7 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #endif
 
 class IPv4Address;

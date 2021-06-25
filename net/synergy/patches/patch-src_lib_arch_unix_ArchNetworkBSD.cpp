$NetBSD: patch-src_lib_arch_unix_ArchNetworkBSD.cpp,v 1.1 2021/06/25 09:49:24 tnn Exp $

https://github.com/symless/synergy-core/issues/7045

--- src/lib/arch/unix/ArchNetworkBSD.cpp.orig	2021-06-08 13:44:14.000000000 +0000
+++ src/lib/arch/unix/ArchNetworkBSD.cpp
@@ -679,6 +679,7 @@ ArchNetworkBSD::nameToAddr(const std::st
     char ipstr[INET6_ADDRSTRLEN];
     struct addrinfo hints;
     struct addrinfo *pResult;
+    struct addrinfo *pOrigResult;
     struct in6_addr serveraddr;
     int ret;
 
@@ -703,6 +704,7 @@ ArchNetworkBSD::nameToAddr(const std::st
         ARCH->unlockMutex(m_mutex);
         throwNameError(ret);
     }
+    pOrigResult = pResult;
 
     for(; pResult != nullptr; pResult = pResult->ai_next ) {
         addresses.push_back(new ArchNetAddressImpl);
@@ -715,7 +717,7 @@ ArchNetworkBSD::nameToAddr(const std::st
         memcpy(&addresses.back()->m_addr, pResult->ai_addr, addresses.back()->m_len);
     }
 
-    freeaddrinfo(pResult);
+    freeaddrinfo(pOrigResult);
     ARCH->unlockMutex(m_mutex);
 
     return addresses;

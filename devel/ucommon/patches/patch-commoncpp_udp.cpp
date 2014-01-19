$NetBSD: patch-commoncpp_udp.cpp,v 1.2 2014/01/19 00:49:06 rodent Exp $

--- commoncpp/udp.cpp.orig	2014-01-04 17:32:41.000000000 +0000
+++ commoncpp/udp.cpp
@@ -409,7 +409,7 @@ Socket::Error UDPSocket::join(const IPV4
     setsockopt(so, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&group, sizeof(group));
     return errSuccess;
 
-#elif defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__)
+#elif defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__) && !defined(__NetBSD__)
 
         struct ip_mreqn      group;
     struct sockaddr_in   myaddr;
@@ -448,7 +448,7 @@ Socket::Error UDPSocket::join(const IPV4
 Socket::Error UDPSocket::getInterfaceIndex(const char *DeviceName,int& InterfaceIndex)
 {
 #ifndef _MSWINDOWS_
-#if defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__)
+#if defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__) && !defined(__NetBSD__)
 
     struct ip_mreqn  mreqn;
     struct ifreq       m_ifreq;

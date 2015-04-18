$NetBSD: patch-commoncpp_udp.cpp,v 1.3 2015/04/18 02:43:24 rodent Exp $

Fix build for NetBSD.

--- commoncpp/udp.cpp.orig	2015-03-24 23:28:03.000000000 +0000
+++ commoncpp/udp.cpp
@@ -317,7 +317,7 @@ Socket::Error UDPSocket::join(const ucom
 Socket::Error UDPSocket::getInterfaceIndex(const char *DeviceName,int& InterfaceIndex)
 {
 #ifndef _MSWINDOWS_
-#if defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__)
+#if defined(IP_ADD_MEMBERSHIP) && defined(SIOCGIFINDEX) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(_OSF_SOURCE) && !defined(__hpux) && !defined(__GNU__) && !defined(__NetBSD__)
 
     struct ip_mreqn  mreqn;
     struct ifreq       m_ifreq;

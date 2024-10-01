$NetBSD: patch-third__party_libwebrtc_rtc__base_physical__socket__server.cc,v 1.1 2024/10/01 15:01:29 ryoon Exp $

--- third_party/libwebrtc/rtc_base/physical_socket_server.cc.orig	2024-07-03 20:25:45.412396416 +0000
+++ third_party/libwebrtc/rtc_base/physical_socket_server.cc
@@ -770,7 +770,7 @@ int PhysicalSocket::TranslateOption(Opti
       return -1;
 #endif
     case OPT_RECV_ECN:
-#if defined(WEBRTC_POSIX)
+#if defined(WEBRTC_POSIX) && defined(IP_RECVTOS)
       if (family_ == AF_INET6) {
         *slevel = IPPROTO_IPV6;
         *sopt = IPV6_RECVTCLASS;

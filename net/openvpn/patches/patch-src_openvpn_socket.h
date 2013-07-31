$NetBSD: patch-src_openvpn_socket.h,v 1.1 2013/07/31 06:53:21 adam Exp $

Fix for systems without ipi_spec_dst in struct in_pktinfo.

--- src/openvpn/socket.h.orig	2013-07-31 06:03:30.000000000 +0000
+++ src/openvpn/socket.h
@@ -84,7 +84,7 @@ struct link_socket_actual
   struct openvpn_sockaddr dest;
 #if ENABLE_IP_PKTINFO
   union {
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
     struct in_pktinfo in4;
 #elif defined(IP_RECVDSTADDR)
     struct in_addr in4;
@@ -580,7 +580,7 @@ addr_defined_ipi (const struct link_sock
 #if ENABLE_IP_PKTINFO
   if (!lsa) return 0;
   switch (lsa->dest.addr.sa.sa_family) {
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && defined(HAVE_IPI_SPEC_DST)
     case AF_INET: return lsa->pi.in4.ipi_spec_dst.s_addr != 0;
 #elif defined(IP_RECVDSTADDR)
     case AF_INET: return lsa->pi.in4.s_addr != 0;

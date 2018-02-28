$NetBSD: patch-snmplib_transports_snmpUDPBaseDomain.c,v 1.1 2018/02/28 01:52:02 maya Exp $

it seems that configure cannot detect IP_PKTINFO correctly
because of using SOL_IP. SOL_IP is not defined on *BSD.
And on netbsd, struct ip_pktinfo has no ipi_spec_dst.
(PR pkg/52945)

--- snmplib/transports/snmpUDPBaseDomain.c.orig	2014-12-08 20:23:22.000000000 +0000
+++ snmplib/transports/snmpUDPBaseDomain.c
@@ -277,7 +277,7 @@ int netsnmp_udpbase_sendto(int fd, struc
              * come from.
              */
             ipi.ipi_ifindex = 0;
-#if defined(cygwin)
+#if defined(cygwin) || defined(__NetBSD__)
             ipi.ipi_addr.s_addr = srcip->s_addr;
 #else
             ipi.ipi_spec_dst.s_addr = srcip->s_addr;
@@ -302,7 +302,7 @@ int netsnmp_udpbase_sendto(int fd, struc
 
             memset(&ipi, 0, sizeof(ipi));
             ipi.ipi_ifindex = if_index;
-#if defined(cygwin)
+#if defined(cygwin) || defined(__NetBSD__)
             ipi.ipi_addr.s_addr = INADDR_ANY;
 #else
             ipi.ipi_spec_dst.s_addr = INADDR_ANY;

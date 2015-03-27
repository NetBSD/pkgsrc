$NetBSD: patch-pdns_nameserver.cc,v 1.4 2015/03/27 23:37:52 rodent Exp $

Do not use IP_PKTINFO on NetBSD.
--- pdns/nameserver.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/nameserver.cc
@@ -81,7 +81,7 @@ extern StatBag S;
     The main() of PowerDNS can be found in receiver.cc - start reading there for further insights into the operation of the nameserver
 */
 
-#if defined(IP_PKTINFO)
+#if defined(IP_PKTINFO) || !defined(__NetBSD__)
   #define GEN_IP_PKTINFO IP_PKTINFO
 #elif defined(IP_RECVDSTADDR)
   #define GEN_IP_PKTINFO IP_RECVDSTADDR 
@@ -337,7 +337,7 @@ static bool HarvestDestinationAddress(st
   memset(destination, 0, sizeof(*destination));
   struct cmsghdr *cmsg;
   for (cmsg = CMSG_FIRSTHDR(msgh); cmsg != NULL; cmsg = CMSG_NXTHDR(msgh,cmsg)) {
-#if defined(IP_PKTINFO)
+#if defined(IP_PKTINFO) || !defined(__NetBSD__)
      if ((cmsg->cmsg_level == IPPROTO_IP) && (cmsg->cmsg_type == IP_PKTINFO)) {
         struct in_pktinfo *i = (struct in_pktinfo *) CMSG_DATA(cmsg);
         destination->sin4.sin_addr = i->ipi_addr;

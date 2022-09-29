$NetBSD: patch-pdns_iputils.cc,v 1.2 2022/09/29 13:49:50 jperkin Exp $

Fix build on NetBSD?

--- pdns/iputils.cc.orig	2022-07-11 13:54:25.000000000 +0000
+++ pdns/iputils.cc
@@ -228,14 +228,14 @@ bool HarvestDestinationAddress(const str
   for (cmsg = CMSG_FIRSTHDR(msgh); cmsg != nullptr; cmsg = CMSG_NXTHDR(const_cast<struct msghdr*>(msgh), const_cast<struct cmsghdr*>(cmsg))) {
 #if defined(IP_PKTINFO)
      if ((cmsg->cmsg_level == IPPROTO_IP) && (cmsg->cmsg_type == IP_PKTINFO)) {
-        struct in_pktinfo *i = (struct in_pktinfo *) CMSG_DATA(cmsg);
+        struct in_pktinfo *i = (struct in_pktinfo *) CMSG_DATA(const_cast<struct cmsghdr *>(cmsg));
         destination->sin4.sin_addr = i->ipi_addr;
         destination->sin4.sin_family = AF_INET;
         return true;
     }
 #elif defined(IP_RECVDSTADDR)
     if ((cmsg->cmsg_level == IPPROTO_IP) && (cmsg->cmsg_type == IP_RECVDSTADDR)) {
-      struct in_addr *i = (struct in_addr *) CMSG_DATA(cmsg);
+      struct in_addr *i = (struct in_addr *) CMSG_DATA(const_cast<struct cmsghdr *>(cmsg));
       destination->sin4.sin_addr = *i;
       destination->sin4.sin_family = AF_INET;      
       return true;
@@ -243,7 +243,7 @@ bool HarvestDestinationAddress(const str
 #endif
 
     if ((cmsg->cmsg_level == IPPROTO_IPV6) && (cmsg->cmsg_type == IPV6_PKTINFO)) {
-        struct in6_pktinfo *i = (struct in6_pktinfo *) CMSG_DATA(cmsg);
+        struct in6_pktinfo *i = (struct in6_pktinfo *) CMSG_DATA(const_cast<struct cmsghdr *>(cmsg));
         destination->sin6.sin6_addr = i->ipi6_addr;
         destination->sin4.sin_family = AF_INET6;
         return true;

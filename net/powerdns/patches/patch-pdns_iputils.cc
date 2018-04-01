$NetBSD: patch-pdns_iputils.cc,v 1.1 2018/04/01 20:28:21 joerg Exp $

--- pdns/iputils.cc.orig	2018-04-01 17:24:16.523211468 +0000
+++ pdns/iputils.cc
@@ -150,14 +150,14 @@ bool HarvestDestinationAddress(const str
   for (cmsg = CMSG_FIRSTHDR(msgh); cmsg != NULL; cmsg = CMSG_NXTHDR(const_cast<struct msghdr*>(msgh), const_cast<struct cmsghdr*>(cmsg))) {
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
@@ -165,7 +165,7 @@ bool HarvestDestinationAddress(const str
 #endif
 
     if ((cmsg->cmsg_level == IPPROTO_IPV6) && (cmsg->cmsg_type == IPV6_PKTINFO)) {
-        struct in6_pktinfo *i = (struct in6_pktinfo *) CMSG_DATA(cmsg);
+        struct in6_pktinfo *i = (struct in6_pktinfo *) CMSG_DATA(const_cast<struct cmsghdr *>(cmsg));
         destination->sin6.sin6_addr = i->ipi6_addr;
         destination->sin4.sin_family = AF_INET6;
         return true;

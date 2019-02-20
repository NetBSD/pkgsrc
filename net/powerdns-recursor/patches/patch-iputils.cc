$NetBSD: patch-iputils.cc,v 1.1 2019/02/20 12:19:44 adam Exp $

Fix buildling.

--- iputils.cc.orig	2019-02-20 10:50:10.609217278 +0000
+++ iputils.cc
@@ -146,7 +146,7 @@ bool HarvestTimestamp(struct msghdr* msg
 bool HarvestDestinationAddress(const struct msghdr* msgh, ComboAddress* destination)
 {
   destination->reset();
-  const struct cmsghdr* cmsg;
+  struct cmsghdr* cmsg;
   for (cmsg = CMSG_FIRSTHDR(msgh); cmsg != NULL; cmsg = CMSG_NXTHDR(const_cast<struct msghdr*>(msgh), const_cast<struct cmsghdr*>(cmsg))) {
 #if defined(IP_PKTINFO)
      if ((cmsg->cmsg_level == IPPROTO_IP) && (cmsg->cmsg_type == IP_PKTINFO)) {

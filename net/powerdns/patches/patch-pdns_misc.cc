$NetBSD: patch-pdns_misc.cc,v 1.2 2015/03/27 23:37:52 rodent Exp $

Do not use IP_PKTINFO on NetBSD.
--- pdns/misc.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/misc.cc
@@ -802,7 +802,7 @@ void addCMsgSrcAddr(struct msghdr* msgh,
     msgh->msg_controllen = cmsg->cmsg_len; // makes valgrind happy and is slightly better style
   }
   else {
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
     struct in_pktinfo *pkt;
 
     msgh->msg_control = cmsgbuf;

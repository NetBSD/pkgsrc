$NetBSD: patch-ntp__io.c,v 1.1 2013/08/31 14:53:45 joerg Exp $

--- ntp_io.c.orig	2013-08-31 11:51:32.000000000 +0000
+++ ntp_io.c
@@ -350,7 +350,7 @@ read_from_socket(void *anything)
     }
 
     for (cmsg = CMSG_FIRSTHDR(&msg); cmsg; cmsg = CMSG_NXTHDR(&msg, cmsg)) {
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
       if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_PKTINFO) {
         struct in_pktinfo ipi;
 
@@ -449,7 +449,7 @@ send_packet(void *packet, int packetlen,
   msg.msg_flags = 0;
   cmsglen = 0;
 
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
   if (remote_addr->local_ip_addr.family == IPADDR_INET4) {
     struct cmsghdr *cmsg;
     struct in_pktinfo *ipi;

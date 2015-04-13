$NetBSD: patch-ntp__io.c,v 1.2 2015/04/13 10:03:21 hannken Exp $

Don't use IP_PKTINFO on NetBSD.

--- ntp_io.c.orig	2015-04-07 14:35:16.000000000 +0000
+++ ntp_io.c
@@ -506,7 +506,7 @@ read_from_socket(void *anything)
     local_addr.sock_fd = sock_fd;
 
     for (cmsg = CMSG_FIRSTHDR(&msg); cmsg; cmsg = CMSG_NXTHDR(&msg, cmsg)) {
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
       if (cmsg->cmsg_level == IPPROTO_IP && cmsg->cmsg_type == IP_PKTINFO) {
         struct in_pktinfo ipi;
 
@@ -623,7 +623,7 @@ send_packet(void *packet, int packetlen,
   msg.msg_flags = 0;
   cmsglen = 0;
 
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
   if (local_addr->ip_addr.family == IPADDR_INET4) {
     struct cmsghdr *cmsg;
     struct in_pktinfo *ipi;

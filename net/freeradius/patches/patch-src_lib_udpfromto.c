$NetBSD: patch-src_lib_udpfromto.c,v 1.1 2017/09/09 22:46:57 joerg Exp $

Only use IP_PKTINFO if the configure checks for the necessary members
passed.

--- src/lib/udpfromto.c.orig	2017-09-09 18:10:18.070426265 +0000
+++ src/lib/udpfromto.c
@@ -386,11 +386,11 @@ int sendfromto(int s, void *buf, size_t 
 	msgh.msg_name = to;
 	msgh.msg_namelen = tolen;
 
-# if defined(IP_PKTINFO) || defined(IP_SENDSRCADDR)
+# if defined(HAVE_IP_PKTINFO) || defined(IP_SENDSRCADDR)
 	if (from->sa_family == AF_INET) {
 		struct sockaddr_in *s4 = (struct sockaddr_in *) from;
 
-#  ifdef IP_PKTINFO
+#  ifdef HAVE_IP_PKTINFO
 		struct cmsghdr *cmsg;
 		struct in_pktinfo *pkt;
 

$NetBSD: patch-src_lib_udpfromto.c,v 1.3 2018/09/25 12:16:36 jperkin Exp $

Only use IP_PKTINFO if the configure checks for the necessary members
passed. Use either IP_PKTINFO or IP_SENDSRCADDR, but not both.

--- src/lib/udpfromto.c.orig	2017-07-17 12:43:00.000000000 +0000
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
 

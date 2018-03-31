$NetBSD: patch-src_lib_udpfromto.c,v 1.2 2018/03/31 20:10:49 joerg Exp $

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
 
@@ -405,9 +405,7 @@ int sendfromto(int s, void *buf, size_t 
 		pkt = (struct in_pktinfo *) CMSG_DATA(cmsg);
 		memset(pkt, 0, sizeof(*pkt));
 		pkt->ipi_spec_dst = s4->sin_addr;
-#  endif
-
-#  ifdef IP_SENDSRCADDR
+#  elif defined(IP_SENDSRCADDR)
 		struct cmsghdr *cmsg;
 		struct in_addr *in;
 

$NetBSD: patch-libs_net_nm_net__udp.c,v 1.1 2019/07/06 22:53:24 nia Exp $

Initialize struct sockaddr_in.

Don't use IN_PKTINFO on NetBSD.

--- libs/net/nm/net_udp.c.orig	2013-01-23 03:10:55.000000000 +0000
+++ libs/net/nm/net_udp.c
@@ -335,7 +335,7 @@ UDP_OpenSocket (int port)
 	if (fcntl (newsocket, F_SETFL, flags | O_NONBLOCK) == -1)
 		goto ErrorReturn;
 #endif
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && !defined(__NetBSD__)
 	if (setsockopt (newsocket, SOL_IP, IP_PKTINFO, &ip_pktinfo,
 					sizeof (ip_pktinfo)) == -1) {
 		close (newsocket);
@@ -343,6 +343,7 @@ UDP_OpenSocket (int port)
 	}
 #endif
 
+	memset(&address, 0, sizeof(address));
 	address.sin_family = AF_INET;
 	address.sin_addr.s_addr = INADDR_ANY;
 	address.sin_port = htons (port);
@@ -470,7 +471,7 @@ UDP_Read (int socket, byte *buf, int len
 {
 	int         ret;
 	AF_address_t addr;
-#ifdef HAVE_IN_PKTINFO
+#if defined(HAVE_IN_PKTINFO) && !defined(__NetBSD__)
 	char        ancillary[CMSG_SPACE (sizeof (struct in_pktinfo))];
 	struct msghdr msghdr = {
 		&addr,

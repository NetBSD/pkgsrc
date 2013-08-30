$NetBSD: patch-lib_kernel_socket.c,v 1.1 2013/08/30 22:39:27 joerg Exp $

--- lib/kernel/socket.c.orig	2013-08-30 20:24:06.000000000 +0000
+++ lib/kernel/socket.c
@@ -976,7 +976,7 @@ recvmsgfrom (int sockfd, u_char *buffer,
 	    else 
 #endif /* HAVE_IPV6 */
 		switch (cmsg->cmsg_type) {
-#ifdef IP_PKTINFO
+#if defined(IP_PKTINFO) && !defined(__NetBSD__)
 		case IP_PKTINFO:
 {
 		    struct in_pktinfo *info;

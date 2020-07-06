$NetBSD: patch-etc_cnid__dbd_usockfd.c,v 1.1 2020/07/06 20:19:54 christos Exp $

Turn on ipv4 encapsulation on ipv6 sockets

--- etc/cnid_dbd/usockfd.c.orig	2016-03-10 03:06:20.000000000 -0500
+++ etc/cnid_dbd/usockfd.c	2020-07-05 22:02:52.137043709 -0400
@@ -114,6 +114,12 @@
         flag = 1;
         setsockopt(sockfd, SOL_TCP, TCP_NODELAY, &flag, sizeof(flag));
 #endif /* USE_TCP_NODELAY */
+
+#ifdef IPV6_V6ONLY
+	/* allow ipv4 encapsulation */
+	flag = 0;
+	setsockopt(sockfd, IPPROTO_IPV6, IPV6_V6ONLY, &flag, sizeof(flag));
+#endif
             
         if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
             close(sockfd);

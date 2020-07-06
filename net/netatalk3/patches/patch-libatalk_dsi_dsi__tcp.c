$NetBSD: patch-libatalk_dsi_dsi__tcp.c,v 1.1 2020/07/06 20:19:54 christos Exp $

Add mapped ipv4 address support

--- libatalk/dsi/dsi_tcp.c.orig	2016-05-20 03:23:56.000000000 -0400
+++ libatalk/dsi/dsi_tcp.c	2020-07-05 22:15:50.293819162 -0400
@@ -363,6 +363,11 @@
         flag = 1;
         setsockopt(dsi->serversock, SOL_TCP, TCP_NODELAY, &flag, sizeof(flag));
 
+#ifdef IPV6_V6ONLY
+	/* allow ipv4 encapsulation */
+	flag = 0;
+	setsockopt(dsi->serversock, IPPROTO_IPV6, IPV6_V6ONLY, &flag, sizeof(flag));
+#endif
         ret = bind(dsi->serversock, p->ai_addr, p->ai_addrlen);
         if (ret == -1) {
             close(dsi->serversock);

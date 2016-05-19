$NetBSD: patch-slirp_tcp__subr.c,v 1.6.18.1 2016/05/19 12:56:38 bsiegert Exp $

--- slirp/tcp_subr.c.orig	2016-05-11 15:56:13.000000000 +0000
+++ slirp/tcp_subr.c
@@ -407,6 +407,8 @@ int tcp_fconnect(struct socket *so, unsi
     socket_set_fast_reuse(s);
     opt = 1;
     qemu_setsockopt(s, SOL_SOCKET, SO_OOBINLINE, &opt, sizeof(opt));
+    opt = 1;
+    qemu_setsockopt(s, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));
 
     addr = so->fhost.ss;
     DEBUG_CALL(" connect()ing")

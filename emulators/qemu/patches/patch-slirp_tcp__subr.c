$NetBSD: patch-slirp_tcp__subr.c,v 1.6 2014/01/15 18:26:20 wiz Exp $

--- slirp/tcp_subr.c.orig	2013-11-27 22:15:55.000000000 +0000
+++ slirp/tcp_subr.c
@@ -340,6 +340,8 @@ int tcp_fconnect(struct socket *so)
     socket_set_fast_reuse(s);
     opt = 1;
     qemu_setsockopt(s, SOL_SOCKET, SO_OOBINLINE, &opt, sizeof(opt));
+    opt = 1;
+    qemu_setsockopt(s, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==

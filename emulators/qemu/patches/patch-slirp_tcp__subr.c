$NetBSD: patch-slirp_tcp__subr.c,v 1.5 2013/07/09 17:00:58 tsutsui Exp $

--- slirp/tcp_subr.c.orig	2013-06-26 21:47:29.000000000 +0000
+++ slirp/tcp_subr.c
@@ -341,6 +341,8 @@ int tcp_fconnect(struct socket *so)
     qemu_setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
     opt = 1;
     qemu_setsockopt(s, SOL_SOCKET, SO_OOBINLINE, &opt, sizeof(opt));
+    opt = 1;
+    qemu_setsockopt(s, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof(opt));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==

$NetBSD: patch-slirp_tcp__subr.c,v 1.4 2013/06/16 18:27:25 tsutsui Exp $

--- slirp/tcp_subr.c.orig	2013-05-24 13:37:57.000000000 +0000
+++ slirp/tcp_subr.c
@@ -341,6 +341,8 @@ int tcp_fconnect(struct socket *so)
     setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(opt ));
     opt = 1;
     setsockopt(s,SOL_SOCKET,SO_OOBINLINE,(char *)&opt,sizeof(opt ));
+    opt = 1;
+    setsockopt(s,IPPROTO_TCP,TCP_NODELAY,(char *)&opt,sizeof(int));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==

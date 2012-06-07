$NetBSD: patch-slirp_tcp__subr.c,v 1.2 2012/06/07 21:23:46 ryoon Exp $

--- slirp/tcp_subr.c.orig	2012-06-01 09:13:13.000000000 +0000
+++ slirp/tcp_subr.c
@@ -341,6 +341,8 @@ int tcp_fconnect(struct socket *so)
     setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(opt ));
     opt = 1;
     setsockopt(s,SOL_SOCKET,SO_OOBINLINE,(char *)&opt,sizeof(opt ));
+    opt = 1;
+    setsockopt(s,IPPROTO_TCP,TCP_NODELAY,(char *)&opt,sizeof(int));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==

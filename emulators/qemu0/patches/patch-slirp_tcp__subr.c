$NetBSD: patch-slirp_tcp__subr.c,v 1.1 2012/06/07 21:35:37 ryoon Exp $

When setting up an outgoing user mode networking TCP connection,
disable the Nagle algorithm in the host-side connection.  Either
the VM is already doing Nagle, in which case there is no point
in doing it twice, or it has chosen to disable it, in which case
we should respect that choice.  This change speeds up GDB remote
debugging over TCP over user mode networking by multiple orders
of magnitude.

--- slirp/tcp_subr.c.orig	2011-10-12 16:41:43.000000000 +0000
+++ slirp/tcp_subr.c
@@ -334,6 +334,8 @@ int tcp_fconnect(struct socket *so)
     setsockopt(s,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(opt ));
     opt = 1;
     setsockopt(s,SOL_SOCKET,SO_OOBINLINE,(char *)&opt,sizeof(opt ));
+    opt = 1;
+    setsockopt(s,IPPROTO_TCP,TCP_NODELAY,(char *)&opt,sizeof(int));
 
     addr.sin_family = AF_INET;
     if ((so->so_faddr.s_addr & slirp->vnetwork_mask.s_addr) ==

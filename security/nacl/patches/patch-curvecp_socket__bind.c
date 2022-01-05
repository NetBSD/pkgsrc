$NetBSD: patch-curvecp_socket__bind.c,v 1.1 2022/01/05 13:51:19 schmonz Exp $

Debian patch 0003-fix-socket_bind.patch:
Fix socket_bind.

--- curvecp/socket_bind.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/socket_bind.c
@@ -9,6 +9,7 @@ int socket_bind(int fd,const unsigned ch
 {
   struct sockaddr_in sa;
   byte_zero(&sa,sizeof sa);
+  sa.sin_family = PF_INET;
   byte_copy(&sa.sin_addr,4,ip);
   byte_copy(&sa.sin_port,2,port);
   return bind(fd,(struct sockaddr *) &sa,sizeof sa);

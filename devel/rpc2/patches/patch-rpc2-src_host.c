$NetBSD: patch-rpc2-src_host.c,v 1.1 2015/01/23 14:31:38 hauke Exp $

SunOS doesn't have u_int*_t

--- rpc2-src/host.c.orig	2009-03-13 20:26:35.000000000 +0000
+++ rpc2-src/host.c
@@ -80,7 +80,7 @@ int HASHHOST(struct RPC2_addrinfo *ai)
     case PF_INET6:
 	{
 	    struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)ai->ai_addr;
-	    lsb = ((u_int32_t *)&sin6->sin6_addr)[3] ^ sin6->sin6_port;
+	    lsb = ((uint32_t *)&sin6->sin6_addr)[3] ^ sin6->sin6_port;
 	    break;
 	}
 #endif

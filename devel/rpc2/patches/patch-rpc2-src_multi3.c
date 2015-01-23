$NetBSD: patch-rpc2-src_multi3.c,v 1.1 2015/01/23 14:31:38 hauke Exp $

SunOS doesn't have u_int*_t

--- rpc2-src/multi3.c.orig	2006-10-13 02:59:51.000000000 +0000
+++ rpc2-src/multi3.c
@@ -89,7 +89,7 @@ int HASHMGRP(struct RPC2_addrinfo *ai, i
 
 #if defined(PF_INET6) 
     case PF_INET6:
-	lsb = ((u_int32_t *)&((struct sockaddr_in6 *)ai->ai_addr)->sin6_addr)[3];
+	lsb = ((uint32_t *)&((struct sockaddr_in6 *)ai->ai_addr)->sin6_addr)[3];
 	break;
 #endif
     }

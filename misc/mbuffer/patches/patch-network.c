$NetBSD: patch-network.c,v 1.2 2018/09/18 09:49:29 fhajny Exp $

Portability fix.

--- network.c.orig	2018-06-25 20:37:20.000000000 +0000
+++ network.c
@@ -118,7 +118,7 @@ void initNetworkInput(const char *addr)
 		hint.ai_family = AddrFam;
 		hint.ai_protocol = IPPROTO_TCP;
 		hint.ai_socktype = SOCK_STREAM;
-#if defined __FreeBSD__ || defined __OpenBSD__
+#if defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
 		hint.ai_flags = AI_ADDRCONFIG;
 #else
 		hint.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;

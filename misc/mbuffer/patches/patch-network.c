$NetBSD: patch-network.c,v 1.1 2014/05/08 11:21:24 jperkin Exp $

Portability fix.

--- network.c.orig	2014-03-10 22:41:15.000000000 +0000
+++ network.c
@@ -114,7 +114,7 @@ void initNetworkInput(const char *addr)
 		hint.ai_family = AddrFam;
 		hint.ai_protocol = IPPROTO_TCP;
 		hint.ai_socktype = SOCK_STREAM;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 		hint.ai_flags = AI_ADDRCONFIG;
 #else
 		hint.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;

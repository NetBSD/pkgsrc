$NetBSD: patch-src_dump.c,v 1.1 2018/10/30 11:16:06 jperkin Exp $

Add IPDEFTTL compat.

--- src/dump.c.orig	2018-10-18 18:21:55.000000000 +0000
+++ src/dump.c
@@ -148,6 +148,9 @@ void dump_packet(int mask, void *packet,
       ip.ip_v = IPVERSION;
       ip.ip_hl = sizeof(struct ip) / 4;
       ip.ip_len = htons(sizeof(struct ip) + sizeof(struct udphdr) + len); 
+#ifndef IPDEFTTL
+#define IPDEFTTL	64
+#endif
       ip.ip_ttl = IPDEFTTL;
       ip.ip_p = IPPROTO_UDP;
       

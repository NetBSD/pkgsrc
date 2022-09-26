$NetBSD: patch-src_dump.c,v 1.2 2022/09/26 13:23:31 adam Exp $

Add IPDEFTTL compat.

--- src/dump.c.orig	2022-09-09 11:53:49.000000000 +0000
+++ src/dump.c
@@ -195,6 +195,9 @@ static void do_dump_packet(int mask, voi
       
       ip.ip_v = IPVERSION;
       ip.ip_hl = sizeof(struct ip) / 4;
+#ifndef IPDEFTTL
+#define IPDEFTTL 64
+#endif
       ip.ip_ttl = IPDEFTTL;
 
       if ((ip.ip_p = proto) == IPPROTO_UDP)

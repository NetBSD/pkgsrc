$NetBSD: patch-src_fping.c,v 1.2 2020/07/12 19:31:03 adam Exp $

Fix for NetBSD-alpha.

--- src/fping.c.orig	2020-07-11 14:27:36.000000000 +0000
+++ src/fping.c
@@ -1877,7 +1877,7 @@ int decode_icmp_ipv4(
     if (!using_sock_dgram4) {
         struct ip* ip = (struct ip*)reply_buf;
 
-#if defined(__alpha__) && __STDC__ && !defined(__GLIBC__)
+#if defined(__alpha__) && __STDC__ && !defined(__GLIBC__) && !defined(__NetBSD__)
         /* The alpha headers are decidedly broken.
          * Using an ANSI compiler, it provides ip_vhl instead of ip_hl and
          * ip_v.  So, to get ip_hl, we mask off the bottom four bits.

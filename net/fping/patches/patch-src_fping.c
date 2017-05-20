$NetBSD: patch-src_fping.c,v 1.1 2017/05/20 11:25:50 adam Exp $

Fix for NetBSD-alpha.

--- src/fping.c.orig	2017-04-23 16:03:08.000000000 +0000
+++ src/fping.c
@@ -1787,7 +1787,7 @@ int decode_icmp_ipv4(
     struct icmp* icp;
     int hlen = 0;
 
-#if defined(__alpha__) && __STDC__ && !defined(__GLIBC__)
+#if defined(__alpha__) && __STDC__ && !defined(__GLIBC__) && !defined(__NetBSD__)
     /* The alpha headers are decidedly broken.
      * Using an ANSI compiler, it provides ip_vhl instead of ip_hl and
      * ip_v.  So, to get ip_hl, we mask off the bottom four bits.

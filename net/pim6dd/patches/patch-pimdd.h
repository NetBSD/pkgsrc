$NetBSD: patch-pimdd.h,v 1.1 2026/06/30 19:55:53 wiz Exp $

Fix build for NetBSD after 2025.

--- pimdd.h.orig	2026-06-30 19:51:10.909831591 +0000
+++ pimdd.h
@@ -532,7 +532,7 @@ do {                                                  
 #define PIM_LEAF_TIMEOUT               (3.5 * IGMP_QUERY_INTERVAL)
 #endif /* NOSUCHDEF */
 
-#if defined(__bsdi__) || defined(__NetBSD__)
+#if defined(__bsdi__) || (defined(__NetBSD__) && !defined(IGMPMSG_NOCACHE))
 /*
  * Struct used to communicate from kernel to multicast router
  * note the convenient similarity to an IP packet

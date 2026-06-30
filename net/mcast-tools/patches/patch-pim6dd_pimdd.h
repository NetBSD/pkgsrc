$NetBSD: patch-pim6dd_pimdd.h,v 1.1 2026/06/30 20:00:02 wiz Exp $

Fix build on NetBSD after 2025.

--- pim6dd/pimdd.h.orig	2026-06-30 19:57:21.128521260 +0000
+++ pim6dd/pimdd.h
@@ -534,7 +534,7 @@ do {                                                  
 #define PIM_LEAF_TIMEOUT               (3.5 * IGMP_QUERY_INTERVAL)
 #endif /* NOSUCHDEF */
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && !defined(IGMPMSG_NOCACHE)
 /*
  * Struct used to communicate from kernel to multicast router
  * note the convenient similarity to an IP packet

$NetBSD: patch-src_stats.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/stats.h.orig	2012-11-19 00:55:46.000000000 +0000
+++ src/stats.h
@@ -52,11 +52,11 @@
  * Function prototypes
  */
 
-inline void stats_init(void);
-inline void stats_update(int type);
-inline void stats_dump(void);
-inline void stats_reset(void);
-inline void stats_pause(void);
-inline void stats_unpause(void);
+void stats_init(void);
+void stats_update(int type);
+void stats_dump(void);
+void stats_reset(void);
+void stats_pause(void);
+void stats_unpause(void);
 
 #endif

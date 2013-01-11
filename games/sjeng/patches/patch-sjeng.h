$NetBSD: patch-sjeng.h,v 1.1 2013/01/11 23:26:36 joerg Exp $

--- sjeng.h.orig	2013-01-11 14:40:45.000000000 +0000
+++ sjeng.h
@@ -153,4 +153,6 @@ typedef time_t rtime_t;
 #define max(x, y) ((x) > (y) ? (x) : (y))
 #define mix(x, y) ((x) < (y) ? (x) : (y))
 
+void init_segtb(void);
+
 #endif

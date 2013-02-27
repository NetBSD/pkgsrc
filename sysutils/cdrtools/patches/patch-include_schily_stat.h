$NetBSD: patch-include_schily_stat.h,v 1.1 2013/02/27 08:40:37 wiz Exp $

Fix typo.

--- include/schily/stat.h.orig	2013-02-12 19:51:21.000000000 +0000
+++ include/schily/stat.h
@@ -290,7 +290,7 @@
 
 #define	stat_set_ansecs(s, n)	((s)->st_atimensec = n)
 #define	stat_set_mnsecs(s, n)	((s)->st_mtimensec = n)
-#define	stat_set_cnsecs(s. n)	((s)->st_ctimensec = n)
+#define	stat_set_cnsecs(s, n)	((s)->st_ctimensec = n)
 
 #define	_FOUND_STAT_NSECS_
 #endif

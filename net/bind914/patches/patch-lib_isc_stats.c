$NetBSD: patch-lib_isc_stats.c,v 1.2 2019/05/20 16:31:08 taca Exp $

* Platform fixes from NetBSD base system.

--- lib/isc/stats.c.orig	2019-05-10 04:51:34.000000000 +0000
+++ lib/isc/stats.c
@@ -30,7 +30,11 @@
 #define ISC_STATS_MAGIC			ISC_MAGIC('S', 't', 'a', 't')
 #define ISC_STATS_VALID(x)		ISC_MAGIC_VALID(x, ISC_STATS_MAGIC)
 
+#ifndef _LP64
+typedef atomic_int_fast32_t isc_stat_t;
+#else
 typedef atomic_int_fast64_t isc_stat_t;
+#endif
 
 struct isc_stats {
 	unsigned int		magic;

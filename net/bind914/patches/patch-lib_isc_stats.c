$NetBSD: patch-lib_isc_stats.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Platform fixes from NetBSD base system.

--- lib/isc/stats.c.orig	2019-04-06 20:09:59.000000000 +0000
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
 	/*% Unlocked */

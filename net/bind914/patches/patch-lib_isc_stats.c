$NetBSD: patch-lib_isc_stats.c,v 1.3 2019/07/18 03:02:02 taca Exp $

* Platform fixes from NetBSD base system.

--- lib/isc/stats.c.orig	2019-07-09 18:15:48.000000000 +0000
+++ lib/isc/stats.c
@@ -30,7 +30,7 @@
 #define ISC_STATS_MAGIC			ISC_MAGIC('S', 't', 'a', 't')
 #define ISC_STATS_VALID(x)		ISC_MAGIC_VALID(x, ISC_STATS_MAGIC)
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 typedef atomic_int_fast32_t isc_stat_t;
 #else
 typedef atomic_int_fast64_t isc_stat_t;

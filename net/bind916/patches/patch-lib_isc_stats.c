$NetBSD: patch-lib_isc_stats.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Platform fixes from NetBSD base system.

--- lib/isc/stats.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/stats.c
@@ -27,7 +27,7 @@
 #define ISC_STATS_MAGIC	   ISC_MAGIC('S', 't', 'a', 't')
 #define ISC_STATS_VALID(x) ISC_MAGIC_VALID(x, ISC_STATS_MAGIC)
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 typedef atomic_int_fast32_t isc__atomic_statcounter_t;
 #else  /* if defined(_WIN32) && !defined(_WIN64) */
 typedef atomic_int_fast64_t isc__atomic_statcounter_t;

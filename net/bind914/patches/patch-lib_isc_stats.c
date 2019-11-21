$NetBSD: patch-lib_isc_stats.c,v 1.4 2019/11/21 05:37:06 taca Exp $

* Platform fixes from NetBSD base system.

--- lib/isc/stats.c.orig	2019-11-06 21:29:49.000000000 +0000
+++ lib/isc/stats.c
@@ -30,7 +30,7 @@
 #define ISC_STATS_MAGIC			ISC_MAGIC('S', 't', 'a', 't')
 #define ISC_STATS_VALID(x)		ISC_MAGIC_VALID(x, ISC_STATS_MAGIC)
 
-#if defined(_WIN32) && !defined(_WIN64)
+#if (defined(_WIN32) && !defined(_WIN64)) || !defined(_LP64)
 	typedef atomic_int_fast32_t isc__atomic_statcounter_t;
 #else
 	typedef atomic_int_fast64_t isc__atomic_statcounter_t;

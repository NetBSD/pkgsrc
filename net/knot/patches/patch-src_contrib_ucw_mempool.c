$NetBSD: patch-src_contrib_ucw_mempool.c,v 1.1 2026/09/11 12:53:13 drixter Exp $

Patch from upstream to work on SmartOS #980

--- src/contrib/ucw/mempool.c.orig	2026-09-10 17:00:32.049321056 +0000
+++ src/contrib/ucw/mempool.c
@@ -17,6 +17,7 @@
 #include <assert.h>
 #include "contrib/macros.h"
 #include "contrib/memcheck.h"
+#include "contrib/string.h"
 #include "contrib/ucw/mempool.h"
 
 #pragma GCC diagnostic ignored "-Wpointer-arith"
@@ -246,7 +247,7 @@ mp_stats_chain(struct mempool *pool, str
 void
 mp_stats(struct mempool *pool, struct mempool_stats *stats)
 {
-	bzero(stats, sizeof(*stats));
+	memzero(stats, sizeof(*stats));
 	mp_stats_chain(pool, pool->state.last[0], stats, 0);
 	mp_stats_chain(pool, pool->state.last[1], stats, 1);
 	mp_stats_chain(pool, pool->unused, stats, 2);

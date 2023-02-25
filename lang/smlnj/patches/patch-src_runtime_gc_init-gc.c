$NetBSD: patch-src_runtime_gc_init-gc.c,v 1.2 2023/02/25 17:58:39 ryoon Exp $

Use struct timeval instead of blithely assuming that some private
struct declaration is always bit compatible with it. (Because it
isn't.) From PR 40954.

--- src/runtime/gc/init-gc.c.orig	2022-07-28 04:55:45.000000000 +0000
+++ src/runtime/gc/init-gc.c
@@ -283,12 +283,16 @@ void InitHeap (ml_state_t *msp, bool_t i
 #if defined(COLLECT_STATS)
     if (StatsFD > 0) {
 	stat_hdr_t	hdr;
+	struct timeval	tv;
 	CNTR_ZERO(&(heap->numAlloc));
 	hdr.mask = STATMASK_ALLOC|STATMASK_NGENS|STATMASK_START|STATMASK_STOP;
 	hdr.isNewRuntime = 1;
 	hdr.allocSzB = params->allocSz;
 	hdr.numGens = params->numGens;
-	gettimeofday (&(hdr.startTime), NIL(struct timezone *));
+	gettimeofday (&tv, NIL(struct timezone *));
+	/* XXX breaks in 2038 */
+	hdr.startTime.seconds = tv.tv_sec;
+	hdr.startTime.uSeconds = tv.tv_usec;
 	write (StatsFD, (char *)&hdr, sizeof(stat_hdr_t));
     }
 #endif

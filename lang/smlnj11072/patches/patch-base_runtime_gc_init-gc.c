$NetBSD: patch-base_runtime_gc_init-gc.c,v 1.1 2016/07/03 18:52:32 dholland Exp $

Use struct timeval instead of blithely assuming that some private
struct declaration is always bit compatible with it. (Because it
isn't.) From PR 40954.

--- base/runtime/gc/init-gc.c.orig	2009-03-03 18:15:36.000000000 -0500
+++ base/runtime/gc/init-gc.c	2009-03-03 18:17:03.000000000 -0500
@@ -218,12 +218,16 @@ void InitHeap (ml_state_t *msp, bool_t i
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


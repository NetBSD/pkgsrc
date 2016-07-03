$NetBSD: patch-base_runtime_gc_gc-stats.h,v 1.1 2016/07/03 18:52:32 dholland Exp $

Use struct timeval instead of blithely assuming that some private
struct declaration is always bit compatible with it. (Because it
isn't.) From PR 40954.

--- base/runtime/gc/gc-stats.h.orig	2009-03-03 18:23:38.000000000 -0500
+++ base/runtime/gc/gc-stats.h	2009-03-03 18:25:04.000000000 -0500
@@ -16,6 +16,7 @@ extern void ReportVM (ml_state_t *msp, i
 
 #define START_GC_PAUSE(HEAP)	{					\
 	if (StatsOn) {							\
+	    struct timeval tv;						\
 	    heap_t	    *__heap = (HEAP);				\
 	    stat_rec_t	    *__p = &(StatsBuf[NStatsRecs]);		\
 	    Unsigned32_t    __n = (Addr_t)(msp->ml_allocPtr) - 		\
@@ -23,7 +24,10 @@ extern void ReportVM (ml_state_t *msp, i
 	    CNTR_INCR(&(__heap->numAlloc), __n);			\
 	    __p->allocCnt = __heap->numAlloc;				\
 	    __p->numGens = 0;						\
-	    gettimeofday(&(__p->startTime), NIL(struct timezone *));	\
+	    gettimeofday(&tv, NIL(struct timezone *));			\
+	    /* XXX breaks in 2038 */					\
+	    __p->startTime.seconds = tv.tv_sec;				\
+	    __p->startTime.uSeconds = tv.tv_usec;			\
 	}								\
     }
 
@@ -34,8 +38,11 @@ extern void ReportVM (ml_state_t *msp, i
 
 #define STOP_GC_PAUSE()			{				\
 	if (StatsOn) {							\
-	    gettimeofday(&(StatsBuf[NStatsRecs].stopTime),		\
-		NIL(struct timezone *));				\
+	    struct timeval tv;						\
+	    gettimeofday(&tv, NIL(struct timezone *));			\
+	    /* XXX breaks in 2038 */					\
+	    StatsBuf[NStatsRecs].stopTime.seconds = tv.tv_sec;		\
+	    StatsBuf[NStatsRecs].stopTime.uSeconds = tv.tv_usec;	\
 	    STATS_FINISH();						\
 	}								\
     }



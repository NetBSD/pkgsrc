$NetBSD: patch-mono_metadata_threads.c,v 1.1 2019/08/25 16:37:01 maya Exp $

If sched_get_priority_{min,max} error, don't try to set a priority.
NetBSD doesn't like SCHED_OTHER + 0 priority, and will error here.

https://github.com/mono/mono/pull/15898

--- mono/metadata/threads.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/metadata/threads.c
@@ -743,6 +743,11 @@ mono_thread_internal_set_priority (MonoI
 #endif
 	MONO_EXIT_GC_SAFE;
 
+	/* Not tunable. Bail out */
+	if ((min == -1) || (max == -1))
+		return;
+
+
 	if (max > 0 && min >= 0 && max > min) {
 		double srange, drange, sposition, dposition;
 		srange = MONO_THREAD_PRIORITY_HIGHEST - MONO_THREAD_PRIORITY_LOWEST;

$NetBSD: patch-src_threading__pthread.m,v 1.1 2022/08/15 14:56:04 ryoon Exp $

* Do not fail under NetBSD.

--- src/threading_pthread.m.orig	2017-10-23 21:05:22.000000000 +0000
+++ src/threading_pthread.m
@@ -40,16 +40,28 @@ struct thread_ctx {
 OF_CONSTRUCTOR()
 {
 	pthread_attr_t pattr;
+
+	OF_ENSURE(pthread_attr_init(&pattr) == 0);
+/*
+ * NetBSD's default policy, SCHED_OTHER, does not support priority.
+ * And sched_get_priority_min() and sched_get_priority_max()
+ * return (-1) in SCHED_OTHER case.
+ */
+#if !defined(OF_NETBSD)
 	int policy;
 	struct sched_param param;
 
-	OF_ENSURE(pthread_attr_init(&pattr) == 0);
 	OF_ENSURE(pthread_attr_getschedpolicy(&pattr, &policy) == 0);
 	OF_ENSURE((minPrio = sched_get_priority_min(policy)) != -1);
 	OF_ENSURE((maxPrio = sched_get_priority_max(policy)) != -1);
 	OF_ENSURE(pthread_attr_getschedparam(&pattr, &param) == 0);
 
 	normalPrio = param.sched_priority;
+#else
+	minPrio = 0;
+	maxPrio = 0;
+	normalPrio = 0;
+#endif
 
 	pthread_attr_destroy(&pattr);
 }

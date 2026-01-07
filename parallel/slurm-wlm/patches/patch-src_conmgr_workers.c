$NetBSD: patch-src_conmgr_workers.c,v 1.1 2026/01/07 18:30:07 adam Exp $

Fix for NetBSD.

--- src/conmgr/workers.c.orig	2026-01-07 12:09:10.586098624 +0000
+++ src/conmgr/workers.c
@@ -121,16 +121,29 @@ static void _worker_delete(void *x)
 
 static int _detect_cpu_count(void)
 {
+#ifdef __NetBSD__
+	cpu_set_t *mask = cpuset_create();
+	cpuset_zero(mask);
+#else
 	cpu_set_t mask = { { 0 } };
+#endif
 	int rc = EINVAL, count = 0;
 
+#ifdef __NetBSD__
+	if ((rc = slurm_getaffinity(getpid(), sizeof(mask), mask))) {
+#else
 	if ((rc = slurm_getaffinity(getpid(), sizeof(mask), &mask))) {
+#endif
 		error("%s: Unable to query assigned CPU mask: %s",
 		      __func__, slurm_strerror(rc));
 		return 0;
 	}
 
+#ifdef __NetBSD__
+	if ((count = task_cpuset_get_assigned_count(sizeof(mask), mask)) < 0)
+#else
 	if ((count = task_cpuset_get_assigned_count(sizeof(mask), &mask)) < 0)
+#endif
 		return 0;
 
 	log_flag(CONMGR, "%s: detected %d CPUs available from kernel",

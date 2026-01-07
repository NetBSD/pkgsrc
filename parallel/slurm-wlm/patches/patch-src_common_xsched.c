$NetBSD: patch-src_common_xsched.c,v 1.1 2026/01/07 18:30:07 adam Exp $

Support NetBSD.

--- src/common/xsched.c.orig	2026-01-07 12:43:55.096159624 +0000
+++ src/common/xsched.c
@@ -120,7 +120,11 @@ extern int task_str_to_cpuset(cpu_set_t 
 #endif
 }
 
+#ifdef __NetBSD__
+extern int slurm_setaffinity(pid_t pid, size_t size, cpu_set_t *mask)
+#else
 extern int slurm_setaffinity(pid_t pid, size_t size, const cpu_set_t *mask)
+#endif
 {
 	int rval;
 	char mstr[CPU_SET_HEX_STR_SIZE];

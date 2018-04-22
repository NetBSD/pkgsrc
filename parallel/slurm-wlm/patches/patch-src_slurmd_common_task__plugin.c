$NetBSD: patch-src_slurmd_common_task__plugin.c,v 1.1 2018/04/22 21:31:09 bacon Exp $

# cpuset functions not standardized across platforms

--- src/slurmd/common/task_plugin.c.orig	2018-01-05 18:03:10.000000000 +0000
+++ src/slurmd/common/task_plugin.c
@@ -542,7 +542,11 @@ extern void task_slurm_chkaffinity(cpu_s
 				   int statval)
 {
 	char *bind_type, *action, *status, *units;
+#ifdef __NetBSD__
+	char mstr[1 + cpuset_size(mask) / 4];
+#else
 	char mstr[1 + CPU_SETSIZE / 4];
+#endif
 	int task_gid = job->envtp->procid;
 	int task_lid = job->envtp->localid;
 	pid_t mypid = job->envtp->task_pid;
@@ -609,7 +613,11 @@ extern char *task_cpuset_to_str(const cp
 	char *ptr = str;
 	char *ret = NULL;
 
+#ifdef __NetBSD__
+	for (base = cpuset_size(mask) - 4; base >= 0; base -= 4) {
+#else
 	for (base = CPU_SETSIZE - 4; base >= 0; base -= 4) {
+#endif
 		char val = 0;
 		if (CPU_ISSET(base, mask))
 			val |= 1;

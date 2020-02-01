$NetBSD: patch-src_slurmd_common_task__plugin.c,v 1.2 2020/02/01 00:15:02 bacon Exp $

# NetBSD specifics

--- src/slurmd/common/task_plugin.c.orig	2020-01-19 02:41:02.593115935 +0000
+++ src/slurmd/common/task_plugin.c
@@ -514,7 +514,11 @@ extern void task_slurm_chkaffinity(cpu_s
 	fatal("%s: not supported on macOS", __func__);
 #else
 	char *bind_type, *action, *status, *units;
-	char mstr[1 + CPU_SETSIZE / 4];
+#ifdef __NetBSD__
+	char mstr[1 + cpuset_size(mask) / 4];
+#else
+ 	char mstr[1 + CPU_SETSIZE / 4];
+#endif
 	int task_gid = job->envtp->procid;
 	int task_lid = job->envtp->localid;
 	pid_t mypid = job->envtp->task_pid;
@@ -585,7 +589,11 @@ extern char *task_cpuset_to_str(const cp
 	char *ptr = str;
 	char *ret = NULL;
 
-	for (base = CPU_SETSIZE - 4; base >= 0; base -= 4) {
+#ifdef __NetBSD__
+	for (base = cpuset_size(mask) - 4; base >= 0; base -= 4) {
+#else
+ 	for (base = CPU_SETSIZE - 4; base >= 0; base -= 4) {
+#endif
 		char val = 0;
 		if (CPU_ISSET(base, mask))
 			val |= 1;

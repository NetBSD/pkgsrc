$NetBSD: patch-src_slurmd_common_task__plugin.h,v 1.2 2025/03/12 18:54:24 adam Exp $

# cpuset functions not standardized across platforms

--- src/slurmd/common/task_plugin.h.orig	2022-05-04 19:32:38.000000000 +0000
+++ src/slurmd/common/task_plugin.h
@@ -48,6 +48,17 @@ typedef cpuset_t cpu_set_t;
 
 #include "src/slurmd/slurmstepd/slurmstepd_job.h"
 
+// Keep in sync with slurmd/slurmd.h
+#ifdef __NetBSD__    
+#define CPU_SETSIZE	MAXCPUS
+#define	cpu_set_t	cpuset_t
+#define CPU_ZERO(c)	cpuset_zero((c))   
+#define CPU_SET(i,c)	cpuset_set((i),(c))
+#define CPU_ISSET(i,c)	cpuset_isset((i),(c))
+#define sched_getaffinity	sched_getaffinity_np
+#define SCHED_GETAFFINITY_THREE_ARGS
+#endif
+ 
 /*
  * Initialize the task plugin.
  *

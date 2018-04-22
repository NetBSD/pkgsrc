$NetBSD: patch-src_slurmd_common_task__plugin.h,v 1.1 2018/04/22 21:31:09 bacon Exp $

# cpuset functions not standardized across platforms

--- src/slurmd/common/task_plugin.h.orig	2018-01-04 21:15:01.000000000 +0000
+++ src/slurmd/common/task_plugin.h
@@ -42,6 +42,16 @@
 
 #include "src/slurmd/slurmstepd/slurmstepd_job.h"
 
+// Keep in sync with slurmd/slurmd.h
+#ifdef __NetBSD__    
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

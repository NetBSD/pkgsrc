$NetBSD: patch-src_common_xsched.h,v 1.1 2026/01/07 18:30:07 adam Exp $

Correct NetBSD support.

--- src/common/xsched.h.orig	2026-01-07 12:05:38.129491083 +0000
+++ src/common/xsched.h
@@ -43,9 +43,14 @@ typedef cpuset_t cpu_set_t;
 #endif
 
 #ifdef __NetBSD__
-#define CPU_ZERO(c) cpuset_zero(*(c))
-#define CPU_ISSET(i, c) cpuset_isset((i), *(c))
+#define CPU_ZERO(c) cpuset_zero((c))
+#define CPU_ISSET(i, c) cpuset_isset((i), (c))
 #define sched_getaffinity sched_getaffinity_np
+#define sched_setaffinity sched_setaffinity_np
+#define cpu_set_t cpuset_t
+#define CPU_SETSIZE MAXCPUS
+#define CPU_SET(i,c) cpuset_set((i), (c))
+#define CPU_COUNT(c) 256
 #endif
 
 #include <sched.h>
@@ -76,7 +81,11 @@ extern char *task_cpuset_to_str(const cp
 extern int task_str_to_cpuset(cpu_set_t *mask, const char *str);
 
 /* Wrapper for sched_setaffinity() */
+#ifdef __NetBSD__
+extern int slurm_setaffinity(pid_t pid, size_t size, cpu_set_t *mask);
+#else
 extern int slurm_setaffinity(pid_t pid, size_t size, const cpu_set_t *mask);
+#endif
 
 /* Wrapper for sched_getaffinity() */
 extern int slurm_getaffinity(pid_t pid, size_t size, cpu_set_t *mask);

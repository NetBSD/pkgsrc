$NetBSD: patch-src_slurmd_slurmd_slurmd.h,v 1.1 2018/04/22 21:31:09 bacon Exp $

# cpuset functions not standardized across platforms

--- src/slurmd/slurmd/slurmd.h.orig	2018-01-04 21:15:01.000000000 +0000
+++ src/slurmd/slurmd/slurmd.h
@@ -48,6 +48,16 @@
 #include "src/common/slurm_protocol_api.h"
 #include "src/common/slurm_cred.h"
 
+// Keep in sync with common/task_plugin.h
+#ifdef __NetBSD__  
+#define CPU_ZERO(c) cpuset_zero((c))
+#define CPU_SET(i,c) cpuset_set((i),(c))
+#define CPU_ISSET(i,c) cpuset_isset((i),(c))
+#define sched_getaffinity sched_getaffinity_np
+#define sched_setaffinity sched_setaffinity_np
+#define SCHED_GETAFFINITY_THREE_ARGS
+#endif
+                        
 #ifndef __USE_XOPEN_EXTENDED
 extern pid_t getsid(pid_t pid);		/* missing from <unistd.h> */
 extern pid_t getpgid(pid_t pid);

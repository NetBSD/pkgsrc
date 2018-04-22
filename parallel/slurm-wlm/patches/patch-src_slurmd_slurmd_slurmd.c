$NetBSD: patch-src_slurmd_slurmd_slurmd.c,v 1.1 2018/04/22 21:31:09 bacon Exp $

# cpuset functions not standardized across platforms

--- src/slurmd/slurmd/slurmd.c.orig	2018-01-04 21:15:01.000000000 +0000
+++ src/slurmd/slurmd/slurmd.c
@@ -2067,7 +2067,13 @@ static int _core_spec_init(void)
 	uint32_t task_params;
 	bool slurmd_off_spec;
 	bitstr_t *res_mac_bitmap;
+#ifdef __NetBSD__
+	cpuset_t *mask = cpuset_create();
+#define	CPU_SET_SIZE	cpuset_size(mask)
+#else
 	cpu_set_t mask;
+#define	CPU_SET_SIZE	sizeof(cpu_set_t)
+#endif
 
 	if ((conf->core_spec_cnt == 0) && (conf->cpu_spec_list == NULL)) {
 		debug("Resource spec: No specialized cores configured by "
@@ -2165,7 +2171,7 @@ static int _core_spec_init(void)
 		rval = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
 					  pid, sizeof(cpu_set_t), &mask);
 #elif defined(SCHED_GETAFFINITY_THREE_ARGS)
-		rval = sched_setaffinity(pid, sizeof(cpu_set_t), &mask);
+		rval = sched_setaffinity(pid, CPU_SET_SIZE, &mask);
 #else
 		rval = sched_setaffinity(pid, &mask);
 #endif

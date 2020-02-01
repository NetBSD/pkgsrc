$NetBSD: patch-src_slurmd_slurmd_slurmd.c,v 1.2 2020/02/01 00:15:02 bacon Exp $

# NetBSD syntax

--- src/slurmd/slurmd/slurmd.c.orig	2020-01-19 02:36:16.111141994 +0000
+++ src/slurmd/slurmd/slurmd.c
@@ -2295,7 +2295,13 @@ static int _core_spec_init(void)
 	uint32_t task_params;
 	bool slurmd_off_spec;
 	bitstr_t *res_mac_bitmap;
-	cpu_set_t mask;
+#ifdef __NetBSD__
+	cpuset_t *mask = cpuset_create();
+#define	CPU_SET_SIZE	cpuset_size(mask)
+#else
+ 	cpu_set_t mask;
+#define	CPU_SET_SIZE	sizeof(cpu_set_t)
+#endif
 
 	if ((conf->core_spec_cnt == 0) && (conf->cpu_spec_list == NULL)) {
 		debug("Resource spec: No specialized cores configured by "
@@ -2393,7 +2399,7 @@ static int _core_spec_init(void)
 		rval = cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
 					  pid, sizeof(cpu_set_t), &mask);
 #else
-		rval = sched_setaffinity(pid, sizeof(cpu_set_t), &mask);
+		rval = sched_setaffinity(pid, CPU_SET_SIZE, &mask);
 #endif
 
 		if (rval != 0) {

$NetBSD: patch-src_control_jobs_control__jobs.c,v 1.1 2011/11/15 21:19:02 jakllsch Exp $

--- src/control/jobs/control_jobs.c.orig	2011-11-07 06:46:13.000000000 +0000
+++ src/control/jobs/control_jobs.c
@@ -540,7 +540,11 @@ int32_t dt_control_export_job_run(dt_job
   // GCC won't accept that this variable is used in a macro, considers
   // it set but not used, which makes for instance Fedora break.
   const __attribute__((__unused__)) int num_threads = MAX(1, MIN(full_entries, darktable.mipmap_cache->num_entries[DT_IMAGE_FULL]) - 1);
+#if defined(__NetBSD__)
+  #pragma omp parallel default(none) private(imgid, size) shared(j, fraction, __sF, w, h, mformat, mstorage, t, sdata, job) num_threads(num_threads) if(num_threads > 1)
+#else
   #pragma omp parallel default(none) private(imgid, size) shared(j, fraction, stderr, w, h, mformat, mstorage, t, sdata, job) num_threads(num_threads) if(num_threads > 1)
+#endif
   {
 #endif
     // get a thread-safe fdata struct (one jpeg struct per thread etc):

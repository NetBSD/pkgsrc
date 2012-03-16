$NetBSD: patch-src_control_jobs_control__jobs.c,v 1.2 2012/03/16 00:35:01 jakllsch Exp $

--- src/control/jobs/control_jobs.c.orig	2012-03-13 21:29:39.000000000 +0000
+++ src/control/jobs/control_jobs.c
@@ -546,7 +546,7 @@ int32_t dt_control_export_job_run(dt_job
   // GCC won't accept that this variable is used in a macro, considers
   // it set but not used, which makes for instance Fedora break.
   const __attribute__((__unused__)) int num_threads = MAX(1, MIN(full_entries, 8));
-#if !defined(__SUNOS__)
+#if !defined(__SUNOS__) && !defined(__NetBSD__)
 #pragma omp parallel default(none) private(imgid, size) shared(control, fraction, w, h, stderr, mformat, mstorage, t, sdata, job, jid, darktable) num_threads(num_threads) if(num_threads > 1)
 #else
 #pragma omp parallel private(imgid, size) shared(control, fraction, w, h, mformat, mstorage, t, sdata, job, jid, darktable) num_threads(num_threads) if(num_threads > 1)

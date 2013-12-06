$NetBSD: patch-src_slurmd_slurmstepd_task.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/slurmd/slurmstepd/task.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/slurmd/slurmstepd/task.c
@@ -501,7 +501,12 @@ _make_tmpdir(slurmd_job_t *job)
 		 * still work with older systems we include this check.
 		 */
 
-#if defined(__FreeBSD__)
+/* FIXME: Come up with a real solution for EUID instead of substituting RUID */
+#if defined(__NetBSD__)
+#define eaccess(p,m) (access((p),(m)))
+#endif
+
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define	__GLIBC__ 		(1)
 #define __GLIBC_PREREQ(a,b)	(1)
 #endif

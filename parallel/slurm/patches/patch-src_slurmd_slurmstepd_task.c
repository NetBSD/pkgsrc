$NetBSD: patch-src_slurmd_slurmstepd_task.c,v 1.2 2018/03/25 14:55:30 bacon Exp $

# Linux compat

--- src/slurmd/slurmstepd/task.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ src/slurmd/slurmstepd/task.c
@@ -558,6 +558,18 @@ _make_tmpdir(stepd_step_rec_t *job)
 		 * still work with older systems we include this check.
 		 */
 
+/* FIXME: Come up with a real solution for EUID instead of substituting RUID */
+#if defined(__NetBSD__)
+#define eaccess(p,m) (access((p),(m)))
+#define HAVE_EACCESS 1
+#endif
+  
+// Unsure about the reason for this patch, but it dates back to SLURM 2.6.4
+//#if defined(__FreeBSD__) || defined(__NetBSD__)
+//#define __GLIBC__               (1) 
+//#define __GLIBC_PREREQ(a,b)     (1) 
+//#endif
+
 #if defined(HAVE_FACCESSAT)
 		else if (faccessat(AT_FDCWD, tmpdir, X_OK|W_OK, AT_EACCESS))
 #elif defined(HAVE_EACCESS)

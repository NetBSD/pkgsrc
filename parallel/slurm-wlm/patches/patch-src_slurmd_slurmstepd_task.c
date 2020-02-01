$NetBSD: patch-src_slurmd_slurmstepd_task.c,v 1.2 2020/02/01 00:15:02 bacon Exp $

# Linux compat

--- src/slurmd/slurmstepd/task.c.orig	2019-12-20 20:44:51.000000000 +0000
+++ src/slurmd/slurmstepd/task.c
@@ -573,6 +573,12 @@ _make_tmpdir(stepd_step_rec_t *job)
 		 * still work with older systems we include this check.
 		 */
 
+/* FIXME: Come up with a real solution for EUID instead of substituting RUID */
+#if defined(__NetBSD__)
+#define eaccess(p,m) (access((p),(m)))
+#define HAVE_EACCESS 1
+#endif
+  
 #if defined(HAVE_FACCESSAT)
 		else if (faccessat(AT_FDCWD, tmpdir, X_OK|W_OK, AT_EACCESS))
 #elif defined(HAVE_EACCESS)

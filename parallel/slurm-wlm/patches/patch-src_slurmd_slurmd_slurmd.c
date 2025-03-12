$NetBSD: patch-src_slurmd_slurmd_slurmd.c,v 1.3 2025/03/12 18:54:24 adam Exp $

NetBSD is also not supported.

--- src/slurmd/slurmd/slurmd.c.orig	2025-03-12 16:19:09.514607833 +0000
+++ src/slurmd/slurmd/slurmd.c
@@ -2310,6 +2310,9 @@ static int _core_spec_init(void)
 #if defined(__APPLE__)
 	error("%s: not supported on macOS", __func__);
 	return SLURM_SUCCESS;
+#elif defined(__NetBSD__)
+	error("%s: not supported on NetBSD", __func__);
+	return SLURM_SUCCESS;
 #else
 	int i, rval;
 	pid_t pid;

$NetBSD: patch-mono_utils_mono-utils-debug.c,v 1.2 2020/02/12 15:25:16 ryoon Exp $

Learn to use kinfo_proc2 on netbsd

--- mono/utils/mono-utils-debug.c.orig	2020-02-04 17:00:34.000000000 +0000
+++ mono/utils/mono-utils-debug.c
@@ -32,6 +32,8 @@ mono_is_usermode_native_debugger_present
 #endif
 #if defined (__NetBSD__)
 #include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 #if defined (_AIX)
 #include <procinfo.h>
@@ -78,8 +80,9 @@ mono_is_usermode_native_debugger_present
 	if (!kd)
 		return FALSE;
 	int count = 0;
-	struct kinfo_proc const * const info = kvm_getprocs (kd, KERN_PROC_PID, getpid (), &count);
-	gboolean const traced = info && count > 0 && (info->kp_proc.p_slflag & PSL_TRACED);
+	int nproc;
+	struct kinfo_proc2 const * const info = kvm_getproc2 (kd, KERN_PROC_PID, getpid (), sizeof(struct kinfo_proc2), &count);
+	gboolean const traced = info && count > 0 && (info->p_flag & P_TRACED);
 	kvm_close (kd);
 	return traced;
 

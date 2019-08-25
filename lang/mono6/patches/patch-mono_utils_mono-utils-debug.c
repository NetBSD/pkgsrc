$NetBSD: patch-mono_utils_mono-utils-debug.c,v 1.1 2019/08/25 16:37:01 maya Exp $

Learn to use kinfo_proc2 on netbsd

--- mono/utils/mono-utils-debug.c.orig	2019-07-18 07:46:08.000000000 +0000
+++ mono/utils/mono-utils-debug.c
@@ -27,10 +27,11 @@ mono_is_usermode_native_debugger_present
 #include <errno.h>
 #include <mono/utils/mono-errno.h>
 #include <fcntl.h>
-#if defined (__APPLE__)
+#if defined (__APPLE__) || defined (__NetBSD__)
 #include <sys/sysctl.h>
 #endif
 #if defined (__NetBSD__)
+#include <sys/proc.h>
 #include <kvm.h>
 #endif
 #if defined (_AIX)
@@ -78,8 +79,9 @@ mono_is_usermode_native_debugger_present
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
 

$NetBSD: patch-mono_utils_mono-utils-debug.c,v 1.3 2020/02/14 00:50:51 kamil Exp $

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
@@ -74,14 +76,23 @@ mono_is_usermode_native_debugger_present
 
 #elif defined (__NetBSD__)
 
-	kvm_t * const kd = kvm_open (NULL, NULL, NULL, KVM_NO_FILES, "kvm_open");
-	if (!kd)
+	struct kinfo_proc2 p;
+	size_t len = sizeof(p);
+	int name[] = {
+		[0] = CTL_KERN,
+		[1] = KERN_PROC2,
+		[2] = KERN_PROC_PID,
+		[3] = getpid(),
+		[4] = (int)(sizeof(struct kinfo_proc2)),
+		[5] = 1
+	};
+
+	const size_t namelen = __arraycount(name);
+
+	if (sysctl(name, namelen, &p, &len, NULL, 0) == -1)
 		return FALSE;
-	int count = 0;
-	struct kinfo_proc const * const info = kvm_getprocs (kd, KERN_PROC_PID, getpid (), &count);
-	gboolean const traced = info && count > 0 && (info->kp_proc.p_slflag & PSL_TRACED);
-	kvm_close (kd);
-	return traced;
+
+	return (p.p_flag & P_TRACED) ? TRUE : FALSE;
 
 #elif defined (_AIX)
 

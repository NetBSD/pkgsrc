$NetBSD: patch-src_ProcessResolver.cpp,v 1.1 2022/04/01 11:53:28 nia Exp $

NetBSD support.

XXX hacky, verify correct

--- src/ProcessResolver.cpp.orig	2022-01-18 01:00:00.338013600 +0000
+++ src/ProcessResolver.cpp
@@ -195,7 +195,6 @@ void ProcessResolver::doResolve() {
 // Implementation for FreeBSD
 #	include <libutil.h>
 #	include <sys/types.h>
-#	include <sys/user.h>
 
 void ProcessResolver::doResolve() {
 	int n_procs;
@@ -221,7 +220,6 @@ void ProcessResolver::doResolve() {
 #	include <kvm.h>
 #	include <paths.h>
 #	include <sys/sysctl.h>
-#	include <sys/user.h>
 
 bool kvm_cleanup(kvm_t *kd) {
 	if (kvm_close(kd) == -1) {
@@ -250,7 +248,11 @@ void ProcessResolver::doResolve() {
 	}
 
 	int n_procs;
+#ifndef __NetBSD__
 	struct kinfo_proc *procs_info = kvm_getprocs(kd, KERN_PROC_PROC, 0, &n_procs);
+#else
+	struct kinfo_proc2 *procs_info = kvm_getproc2(kd, KERN_PROC2, 0, sizeof(struct kinfo_proc2), &n_procs);
+#endif
 	if (!procs_info) {
 #	ifndef QT_NO_DEBUG
 		qCritical("ProcessResolver: kvm_getprocs() failed\n");
@@ -261,7 +263,11 @@ void ProcessResolver::doResolve() {
 	}
 
 	for (int i = 0; i < n_procs; ++i) {
+#ifndef __NetBSD__
 		addEntry(procs_info[i].ki_pid, procs_info[i].ki_comm, m_processMap);
+#else
+		addEntry(procs_info[i].p_pid, procs_info[i].p_comm, m_processMap);
+#endif
 	}
 
 	kvm_cleanup(kd);

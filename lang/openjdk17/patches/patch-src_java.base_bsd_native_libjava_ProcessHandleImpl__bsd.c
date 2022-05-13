$NetBSD: patch-src_java.base_bsd_native_libjava_ProcessHandleImpl__bsd.c,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/java.base/bsd/native/libjava/ProcessHandleImpl_bsd.c.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/java.base/bsd/native/libjava/ProcessHandleImpl_bsd.c
@@ -46,7 +46,7 @@
 #include <sys/user.h>  // For kinfo_proc
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && __NetBSD_Version < 799002700)
 #include <sys/event.h> // For kqueue
 #include <sys/time.h>  // For kqueue
 #endif
@@ -413,6 +413,9 @@ void os_getCmdlineAndUserInfo(JNIEnv *en
     size = sizeof(cmd);
     mib[0] = CTL_KERN;
     mib[1] = KERN_PROC;
+#if defined(__NetBSD__) && !defined(KERN_PROC_PATHAME)
+#define KERN_PROC_PATHNAME 5
+#endif
     mib[2] = KERN_PROC_PATHNAME;
     mib[3] = pid;
     if (sysctl(mib, 4, cmd, &size, NULL, 0) == -1) {
@@ -488,7 +491,7 @@ void os_getCmdlineAndUserInfo(JNIEnv *en
 #endif
 }
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && __NetBSD_Version < 80000000)
 int os_waitForProcessExitNoReap(pid_t pid) {
     int kq, ret;
     struct kevent evSet;

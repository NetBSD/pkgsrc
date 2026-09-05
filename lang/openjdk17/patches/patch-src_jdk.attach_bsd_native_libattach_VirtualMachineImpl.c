$NetBSD: patch-src_jdk.attach_bsd_native_libattach_VirtualMachineImpl.c,v 1.2 2026/09/05 09:44:05 tnn Exp $

Fix casting issue?

--- src/jdk.attach/bsd/native/libattach/VirtualMachineImpl.c.orig	2025-11-01 06:28:57.000000000 +0000
+++ src/jdk.attach/bsd/native/libattach/VirtualMachineImpl.c
@@ -31,7 +31,9 @@
 #include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/un.h>
+#if !defined(__NetBSD__)
 #include <sys/user.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <signal.h>
@@ -163,8 +165,8 @@ JNIEXPORT jboolean JNICALL Java_sun_tool
     */
 
     if (sysctl(mib, sizeof(mib) / sizeof(int), &kiproc, &kipsz, NULL, 0) == 0) {
-        const bool ignored = sigismember(&kiproc.KI_SIGIGNORE, SIGQUIT) != 0;
-        const bool caught  = sigismember(&kiproc.KI_SIGCATCH, SIGQUIT)  != 0;
+        const bool ignored = sigismember((sigset_t *)(&kiproc.KI_SIGIGNORE), SIGQUIT) != 0;
+        const bool caught  = sigismember((sigset_t *)(&kiproc.KI_SIGCATCH), SIGQUIT)  != 0;
 
         // note: obviously the masks could change between testing and signalling however this is not the
         // observed behavior of the current JVM implementation.

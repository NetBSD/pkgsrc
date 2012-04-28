$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread.h,v 1.2 2012/04/28 16:56:59 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread.h.orig	2012-04-20 22:40:05.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread.h
@@ -25,6 +25,8 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY) || defined (OS_NETBSD)
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;

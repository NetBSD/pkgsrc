$NetBSD: patch-ipc_chromium_src_base_platform__thread.h,v 1.1 2012/03/06 12:34:09 ryoon Exp $

--- ipc/chromium/src/base/platform_thread.h.orig	2011-12-20 23:28:19.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
@@ -25,6 +25,8 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_FREEBSD) || defined(OS_DRAGONFLY) || defined (OS_NETBSD)
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;

$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread.h,v 1.4 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread.h.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread.h
@@ -25,6 +25,9 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(__GLIBC__)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_SOLARIS)
+#include <sys/lwp.h>
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_BSD)
 #include <sys/types.h>
 typedef lwpid_t PlatformThreadId;

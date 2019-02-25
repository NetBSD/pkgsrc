$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.3 2019/02/25 15:32:24 wiz Exp $

* Support NetBSD
* Support Solaris (we can't rely on pthread_setname_np so ignore it).

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2019-02-23 20:00:48.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,9 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
@@ -100,7 +102,7 @@ void PlatformThread::SetName(const char*
   pthread_setname_np(pthread_self(), "%s", (void*)name);
 #elif defined(OS_BSD) && !defined(__GLIBC__)
   pthread_set_name_np(pthread_self(), name);
-#elif defined(OS_SOLARIS)
+#elif defined(notOS_SOLARIS)
   pthread_setname_np(pthread_self(), name);
 #else
 #endif

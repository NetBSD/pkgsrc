$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.5 2012/05/08 19:29:36 martin Exp $

# Reported upstream: https://bugzilla.mozilla.org/show_bug.cgi?id=753046

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2012-03-13 01:36:53.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,9 +9,18 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#elif defined(OS_NETBSD)
+#include <lwp.h>
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <unistd.h>
+#elif defined(OS_DRAGONFLY)
+#include <unistd.h>
+#elif defined(OS_FREEBSD)
+#include <sys/thr.h>
+_Pragma("GCC visibility push(default)")
+# include <pthread_np.h>
+_Pragma("GCC visibility pop")
 #endif
 
 #if defined(OS_MACOSX)
@@ -33,6 +42,18 @@ PlatformThreadId PlatformThread::Current
   // into the kernel.
 #if defined(OS_MACOSX)
   return mach_thread_self();
+#elif defined(OS_NETBSD)
+  return _lwp_self();
+#elif defined(OS_DRAGONFLY)
+  return lwp_gettid();
+#elif defined(OS_FREEBSD)
+#  if __FreeBSD_cc_version > 900000
+    return pthread_getthreadid_np();
+#  else
+    lwpid_t lwpid;
+    thr_self( &lwpid );
+    return lwpid;
+#  endif
 #elif defined (__OpenBSD__)
   // TODO(BSD): find a better thread ID
   return (intptr_t)(pthread_self());

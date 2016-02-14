$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.1 2016/02/14 07:30:54 ryoon Exp $

* Just because OS_ARCH is Darwin does not mean MacOS X specific
  kludges are needed.

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2014-05-06 22:55:41.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -9,8 +9,12 @@
 
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
+#include <dlfcn.h>
+#include <string>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
@@ -19,15 +23,13 @@
 #include <sys/thr.h>
 #endif
 
-#if !defined(OS_MACOSX)
 #include <unistd.h>
-#endif
 
 #if defined(OS_BSD) && !defined(OS_NETBSD) && !defined(__GLIBC__)
 #include <pthread_np.h>
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 namespace base {
 void InitThreading();
 }  // namespace
@@ -91,7 +93,7 @@ void PlatformThread::Sleep(int duration_
     sleep_time = remaining;
 }
 
-#ifndef OS_MACOSX
+#ifndef MOZ_WIDGET_COCOA
 // Mac is implemented in platform_thread_mac.mm.
 
 // static
@@ -114,19 +116,41 @@ void PlatformThread::SetName(const char*
   pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif defined(OS_BSD) && !defined(__GLIBC__)
   pthread_set_name_np(pthread_self(), name);
-#else
+#elif defined(OS_MACOSX)
+  // Copied from platform_thread_mac.mm
+
+  // pthread_setname_np is only available in 10.6 or later, so test
+  // for it at runtime.
+  int (*dynamic_pthread_setname_np)(const char*);
+  *reinterpret_cast<void**>(&dynamic_pthread_setname_np) =
+      dlsym(RTLD_DEFAULT, "pthread_setname_np");
+  if (!dynamic_pthread_setname_np)
+    return;
+
+  // Mac OS X does not expose the length limit of the name, so
+  // hardcode it.
+  const int kMaxNameLength = 63;
+  std::string shortened_name = std::string(name).substr(0, kMaxNameLength);
+  // pthread_setname() fails (harmlessly) in the sandbox, ignore when it does.
+  // See http://crbug.com/47058
+
+  // The name parameter is copied thus it's safe to release it after calling.
+  // Checked against the bionic implementation in bionic/libc/bionic/pthread.c
+  dynamic_pthread_setname_np(shortened_name.c_str());
+#elif !defined(OS_SOLARIS)
+  prctl(PR_SET_NAME, reinterpret_cast<uintptr_t>(name), 0, 0, 0);
 #endif
 }
-#endif // !OS_MACOSX
+#endif // !MOZ_WIDGET_COCOA
 
 namespace {
 
 bool CreateThread(size_t stack_size, bool joinable,
                   PlatformThread::Delegate* delegate,
                   PlatformThreadHandle* thread_handle) {
-#if defined(OS_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   base::InitThreading();
-#endif  // OS_MACOSX
+#endif  // MOZ_WIDGET_COCOA
 
   bool success = false;
   pthread_attr_t attributes;

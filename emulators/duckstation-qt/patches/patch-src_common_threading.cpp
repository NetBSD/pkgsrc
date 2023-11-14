$NetBSD: patch-src_common_threading.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/common/threading.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/common/threading.cpp
@@ -33,7 +33,7 @@
 #include <mach/mach_time.h>
 #include <mach/semaphore.h>
 #include <mach/task.h>
-#else
+#elif defined (__linux__)
 #include <pthread_np.h>
 #endif
 #endif
@@ -473,8 +473,10 @@ u64 Threading::GetThreadCpuTime()
   return user.u64time + kernel.u64time;
 #elif defined(__APPLE__)
   return getthreadtime(pthread_mach_thread_np(pthread_self()));
-#else
+#elif defined(__linux__)
   return get_thread_time(nullptr);
+#else
+  return 0;
 #endif
 }
 
@@ -556,6 +558,8 @@ void Threading::SetNameOfCurrentThread(c
   prctl(PR_SET_NAME, name, 0, 0, 0);
 #elif defined(__APPLE__)
   pthread_setname_np(name);
+#elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #else
   pthread_set_name_np(pthread_self(), name);
 #endif

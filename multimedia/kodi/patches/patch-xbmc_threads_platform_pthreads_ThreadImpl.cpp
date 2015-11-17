$NetBSD: patch-xbmc_threads_platform_pthreads_ThreadImpl.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/threads/platform/pthreads/ThreadImpl.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/threads/platform/pthreads/ThreadImpl.cpp
@@ -35,6 +35,10 @@
 #include <pthread_np.h>
 #endif
 #endif
+#if defined(TARGET_NETBSD)
+#include <unistd.h>
+#include <lwp.h>
+#endif
 
 #include <signal.h>
 
@@ -42,7 +46,11 @@ void CThread::SpawnThread(unsigned stack
 {
   pthread_attr_t attr;
   pthread_attr_init(&attr);
-#if !defined(TARGET_ANDROID) // http://code.google.com/p/android/issues/detail?id=7808
+#if defined(TARGET_NETBSD)
+  const long stack_min = sysconf(_SC_THREAD_STACK_MIN);
+  if (stack_min != -1 && stacksize > (unsigned)stack_min)
+    pthread_attr_setstacksize(&attr, stacksize);
+#elif !defined(TARGET_ANDROID) // http://code.google.com/p/android/issues/detail?id=7808
   if (stacksize > PTHREAD_STACK_MIN)
     pthread_attr_setstacksize(&attr, stacksize);
 #endif
@@ -66,6 +74,8 @@ void CThread::SetThreadInfo()
 #else
   m_ThreadOpaque.LwpId = pthread_getthreadid_np();
 #endif
+#elif defined(TARGET_NETBSD)
+  m_ThreadOpaque.LwpId = _lwp_self();
 #elif defined(TARGET_ANDROID)
   m_ThreadOpaque.LwpId = gettid();
 #else
@@ -77,6 +87,8 @@ void CThread::SetThreadInfo()
 #if(__MAC_OS_X_VERSION_MIN_REQUIRED >= 1060 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 30200)
   pthread_setname_np(m_ThreadName.c_str());
 #endif
+#elif defined(TARGET_NETBSD)
+  pthread_setname_np(m_ThreadId, "%s", (void *)(intptr_t)m_ThreadName.c_str());
 #else
   pthread_setname_np(m_ThreadId, m_ThreadName.c_str());
 #endif
@@ -243,7 +255,10 @@ int64_t CThread::GetAbsoluteUsage()
     // System time.
     time += (((int64_t)threadInfo.system_time.seconds * 10000000L) + threadInfo.system_time.microseconds*10L);
   }
-
+#elif defined(TARGET_NETBSD)
+  struct timespec tp;
+  clock_gettime(CLOCK_VIRTUAL, &tp);
+  time = (int64_t)tp.tv_sec * 10000000 + tp.tv_nsec/100;
 #else
   clockid_t clock;
   if (pthread_getcpuclockid(m_ThreadId, &clock) == 0)

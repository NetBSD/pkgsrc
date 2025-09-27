$NetBSD: patch-third__party_kineto_libkineto_src_ThreadUtil.cpp,v 1.2 2025/09/27 01:19:55 ryoon Exp $

* Support NetBSD.

--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2025-08-06 17:08:03.000000000 +0000
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -27,6 +27,10 @@
 #undef ERROR
 #endif // _WIN32
 
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
+
 #ifdef __ANDROID__
 #include <sys/prctl.h>
 #endif
@@ -90,6 +94,8 @@ int32_t systemThreadId(bool cache) {
     syscall(SYS_thr_self, &sysTid);
 #elif defined _AIX
     sysTid = pthread_self();
+#elif defined __NetBSD__
+    sysTid = (int32_t)_lwp_self();
 #else
     sysTid = (int32_t)syscall(SYS_gettid);
 #endif
@@ -161,6 +167,8 @@ bool setThreadName(const std::string& na
   return SUCCEEDED(hr);
 #elif defined _AIX
   return 0;
+#elif defined(__NetBSD__)
+  return 0 == pthread_setname_np(pthread_self(), "thread_%s", const_cast<char *>(name.c_str()));
 #else
   return 0 == pthread_setname_np(pthread_self(), name.c_str());
 #endif

$NetBSD: patch-third__party_kineto_libkineto_src_ThreadUtil.cpp,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Support NetBSD.

--- third_party/kineto/libkineto/src/ThreadUtil.cpp.orig	2024-10-29 18:00:46.000000000 +0000
+++ third_party/kineto/libkineto/src/ThreadUtil.cpp
@@ -23,6 +23,10 @@
 #undef ERROR
 #endif // _WIN32
 
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
+
 #ifdef __ANDROID__
 #include <sys/prctl.h>
 #endif
@@ -58,6 +62,8 @@ int32_t systemThreadId() {
     _sysTid = (int32_t)GetCurrentThreadId();
 #elif defined __FreeBSD__
     syscall(SYS_thr_self, &_sysTid);
+#elif defined __NetBSD__
+    _sysTid = (int32_t)_lwp_self();
 #else
     _sysTid = (int32_t)syscall(SYS_gettid);
 #endif
@@ -111,6 +117,8 @@ bool setThreadName(const std::string& na
   std::wstring wname = conv.from_bytes(name);
   HRESULT hr = _SetThreadDescription(GetCurrentThread(), wname.c_str());
   return SUCCEEDED(hr);
+#elif defined(__NetBSD__)
+  return 0 == pthread_setname_np(pthread_self(), "thread_%s", const_cast<char *>(name.c_str()));
 #else
   return 0 == pthread_setname_np(pthread_self(), name.c_str());
 #endif

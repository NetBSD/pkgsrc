$NetBSD: patch-src_framework_global_runtime.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Fix pthread_setname_np() args for NetBSD.

--- src/framework/global/runtime.cpp.orig	2025-07-21 11:30:01.257512152 +0000
+++ src/framework/global/runtime.cpp
@@ -45,6 +45,11 @@ void muse::runtime::setThreadName(const 
     if (pthread_setname_np(pthread_self(), truncated_name.c_str()) > 0) {
         LOGW() << "Couldn't set thread name through pthreads";
     }
+#elif defined(Q_OS_NETBSD)
+    DO_ASSERT(name.length() <= PTHREAD_MAX_NAMELEN_NP);
+    if (pthread_setname_np(pthread_self(), name.c_str(), nullptr) != 0) {
+        LOGW() << "Couldn't set thread name through pthreads";
+    }
 #elif defined(Q_OS_MACOS)
     pthread_setname_np(name.c_str());
 #endif

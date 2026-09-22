$NetBSD: patch-src_mongo_platform_process__id.cpp,v 1.1 2026/09/22 16:47:10 abs Exp $

Add getCurrentNativeThreadId() implementation for NetBSD

--- src/mongo/platform/process_id.cpp.orig	2026-01-10 17:09:51.945999791 +0000
+++ src/mongo/platform/process_id.cpp
@@ -73,6 +73,10 @@ inline NativeProcessId getCurrentNativeT
     invariant(::pthread_threadid_np(NULL, &tid) == 0);
     return tid;
 }
+#elif __NetBSD__
+inline NativeProcessId getCurrentNativeThreadId() {
+    return (intptr_t)pthread_self();
+}
 #else
 inline NativeProcessId getCurrentNativeThreadId() {
     return ::syscall(SYS_gettid);

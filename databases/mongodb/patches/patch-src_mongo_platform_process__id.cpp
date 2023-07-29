$NetBSD: patch-src_mongo_platform_process__id.cpp,v 1.1 2023/07/29 11:45:43 adam Exp $

NetBSD support.

--- src/mongo/platform/process_id.cpp.orig	2023-07-28 09:20:38.330632095 +0000
+++ src/mongo/platform/process_id.cpp
@@ -81,6 +81,10 @@ inline NativeProcessId getCurrentNativeT
 inline NativeProcessId getCurrentNativeThreadId() {
     return pthread_getthreadid_np();
 }
+#elif __NetBSD__
+inline NativeProcessId getCurrentNativeThreadId() {
+    return (intptr_t)pthread_self();
+}
 #else
 inline NativeProcessId getCurrentNativeThreadId() {
     return ::syscall(SYS_gettid);

$NetBSD: patch-va_va__trace.c,v 1.3 2018/11/23 08:05:04 ryoon Exp $

attempt to provide syscall(__NR_gettid) for most
systems. inspired by lldb Host.cpp

--- va/va_trace.c.orig	2018-10-23 13:50:59.000000000 +0000
+++ va/va_trace.c
@@ -50,10 +50,31 @@
 #include <sys/stat.h>
 #include <sys/syscall.h>
 #include <pthread.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <pthread_np.h>
+#endif
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 #include <unistd.h>
 #include <time.h>
 #include <errno.h>
 
+pid_t get_tid() {
+#if defined(__linux__)
+    return syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    return _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    return pthread_getthreadid_np();
+#elif defined(__OpenBSD__)
+    return syscall(SYS_getthrid);
+#else
+#warning "Don't know how to get thread id"
+    return 0;
+#endif
+}
+
 /*
  * Env. to debug some issue, e.g. the decode/encode issue in a video conference scenerio:
  * .LIBVA_TRACE=log_file: general VA parameters saved into log_file
@@ -290,7 +311,7 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
 
     LOCK_RESOURCE(pva_trace);
 
@@ -668,7 +689,7 @@ static struct trace_log_file *start_trac
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -707,7 +728,7 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1230,7 +1251,7 @@ static void internal_TraceUpdateContext 
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;

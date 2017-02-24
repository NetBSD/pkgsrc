$NetBSD: patch-va_va__trace.c,v 1.2 2017/02/24 16:44:03 maya Exp $

attempt to provide syscall(__NR_gettid) for most
systems. inspired by lldb Host.cpp

--- va/va_trace.c.orig	2016-11-10 00:34:35.000000000 +0000
+++ va/va_trace.c
@@ -48,6 +48,12 @@
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
@@ -235,6 +241,21 @@ struct va_trace {
 
 /* Prototype declarations (functions defined in va.c) */
 
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
 void va_errorMessage(const char *msg, ...);
 void va_infoMessage(const char *msg, ...);
 
@@ -294,7 +315,7 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
 
     LOCK_RESOURCE(pva_trace);
 
@@ -318,7 +339,7 @@ static void delete_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
 
     LOCK_RESOURCE(pva_trace);
 
@@ -665,7 +686,7 @@ static struct trace_log_file *start_trac
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -704,7 +725,7 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1226,7 +1247,7 @@ static void internal_TraceUpdateContext 
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
-    pid_t thd_id = syscall(__NR_gettid);
+    pid_t thd_id = get_tid();
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;

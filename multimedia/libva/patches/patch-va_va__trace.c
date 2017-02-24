$NetBSD: patch-va_va__trace.c,v 1.1 2017/02/24 03:25:36 maya Exp $

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
@@ -294,7 +300,13 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#if defined(__linux__)
     pid_t thd_id = syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    pid_t thd_id = _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    pid_t thd_id = pthread_getthreadid_np();
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -318,7 +330,13 @@ static void delete_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#if defined(__linux__)
     pid_t thd_id = syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    pid_t thd_id = _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    pid_t thd_id = pthread_getthreadid_np();
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -665,7 +683,13 @@ static struct trace_log_file *start_trac
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
+#if defined(__linux__)
     pid_t thd_id = syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    pid_t thd_id = _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    pid_t thd_id = pthread_getthreadid_np();
+#endif
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -704,7 +728,13 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
+#if defined(__linux__)
     pid_t thd_id = syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    pid_t thd_id = _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    pid_t thd_id = pthread_getthreadid_np();
+#endif
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1226,7 +1256,13 @@ static void internal_TraceUpdateContext 
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
+#if defined(__linux__)
     pid_t thd_id = syscall(__NR_gettid);
+#elif defined(__NetBSD__)
+    pid_t thd_id = _lwp_self();
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+    pid_t thd_id = pthread_getthreadid_np();
+#endif
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;

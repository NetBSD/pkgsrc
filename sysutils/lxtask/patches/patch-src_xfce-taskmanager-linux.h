$NetBSD: patch-src_xfce-taskmanager-linux.h,v 1.1 2016/08/17 15:19:42 richard Exp $
fix declaration to be the same as the implementation.

--- src/xfce-taskmanager-linux.h.orig	2014-09-16 12:27:52.000000000 +0000
+++ src/xfce-taskmanager-linux.h
@@ -38,7 +38,7 @@
 #define SIGNAL_CONT SIGCONT
 #define SIGNAL_STOP SIGSTOP
 
-void get_task_details(gint pid,struct task *task);
+void get_task_details(pid_t pid,struct task *task);
 GArray *get_task_list(void);
 gboolean get_system_status(system_status *sys_stat);
 gboolean get_cpu_usage_from_proc(system_status *sys_stat);

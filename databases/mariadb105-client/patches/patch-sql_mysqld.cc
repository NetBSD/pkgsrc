$NetBSD: patch-sql_mysqld.cc,v 1.2 2024/06/20 18:53:56 abs Exp $

Add missing declaration of "concurrency".
Fixes build on illumos. From OmniOS CE.

Apply https://github.com/MariaDB/server/pull/3253 to avoid
hang on exit on at least NetBSD (and presumably macOS)

--- sql/mysqld.cc.orig	2024-06-20 16:21:36.964589822 +0000
+++ sql/mysqld.cc
@@ -453,7 +453,7 @@ Atomic_counter<uint32_t> THD_count::coun
 bool shutdown_wait_for_slaves;
 Atomic_counter<uint32_t> slave_open_temp_tables;
 ulong thread_created;
-ulong back_log, connect_timeout, server_id;
+ulong back_log, connect_timeout, concurrency, server_id;
 ulong what_to_log;
 ulong slow_launch_time;
 ulong open_files_limit, max_binlog_size;
@@ -3205,6 +3205,15 @@ static void start_signal_handler(void)
   DBUG_VOID_RETURN;
 }
 
+/** Called only from signal_hand function. */
+static void* exit_signal_handler()
+{
+    my_thread_end();
+    signal_thread_in_use= 0;
+    pthread_exit(0);  // Safety
+    return nullptr;  // Avoid compiler warnings
+}
+
 
 /** This threads handles all signals and alarms. */
 /* ARGSUSED */
@@ -3265,10 +3274,7 @@ pthread_handler_t signal_hand(void *arg 
     if (abort_loop)
     {
       DBUG_PRINT("quit",("signal_handler: calling my_thread_end()"));
-      my_thread_end();
-      signal_thread_in_use= 0;
-      pthread_exit(0);				// Safety
-      return 0;                                 // Avoid compiler warnings
+      return exit_signal_handler();
     }
     switch (sig) {
     case SIGTERM:
@@ -3287,6 +3293,7 @@ pthread_handler_t signal_hand(void *arg 
         PSI_CALL_delete_current_thread();
         my_sigset(sig, SIG_IGN);
         break_connect_loop(); // MIT THREAD has a alarm thread
+        return exit_signal_handler();
       }
       break;
     case SIGHUP:

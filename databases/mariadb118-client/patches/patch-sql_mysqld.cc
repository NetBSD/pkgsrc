$NetBSD: patch-sql_mysqld.cc,v 1.2 2025/06/20 14:03:21 nia Exp $

Build fixes for illumos. From OmniOS CE.

--- sql/mysqld.cc.orig	2025-05-21 14:08:47.000000000 +0000
+++ sql/mysqld.cc
@@ -429,7 +429,7 @@ char* opt_secure_file_priv;
 my_bool lower_case_file_system= 0;
 my_bool opt_large_pages= 0;
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-my_bool opt_super_large_pages= 0;
+extern my_bool opt_super_large_pages;
 #endif
 my_bool opt_myisam_use_mmap= 0;
 uint   opt_large_page_size= 0;
@@ -473,7 +473,7 @@ Atomic_counter<uint32_t> slave_open_temp
 */
 Atomic_counter<ulonglong> sending_new_binlog_file;
 ulong thread_created;
-ulong back_log, connect_timeout, server_id;
+ulong back_log, connect_timeout, server_id, concurrency;
 ulong what_to_log;
 ulong slow_launch_time;
 ulong open_files_limit, max_binlog_size;

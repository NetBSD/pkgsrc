$NetBSD: patch-sql_mysqld.cc,v 1.1 2024/08/21 21:08:34 nia Exp $

Add missing declaration of "concurrency".
Fixes build on illumos. From OmniOS CE.

--- sql/mysqld.cc.orig	2024-08-21 18:47:03.556109771 +0000
+++ sql/mysqld.cc
@@ -467,7 +467,7 @@ Atomic_counter<uint32_t> slave_open_temp
 */
 Atomic_counter<ulonglong> sending_new_binlog_file;
 ulong thread_created;
-ulong back_log, connect_timeout, server_id;
+ulong back_log, connect_timeout, server_id, concurrency;
 ulong what_to_log;
 ulong slow_launch_time;
 ulong open_files_limit, max_binlog_size;

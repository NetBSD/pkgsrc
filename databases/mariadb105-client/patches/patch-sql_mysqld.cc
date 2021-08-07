$NetBSD: patch-sql_mysqld.cc,v 1.1 2021/08/07 09:24:07 nia Exp $

Add missing declaration of "concurrency".
Fixes build on illumos. From OmniOS CE.

--- sql/mysqld.cc.orig	2021-08-03 14:48:41.000000000 +0000
+++ sql/mysqld.cc
@@ -443,7 +443,7 @@ Atomic_counter<uint32_t> THD_count::coun
 bool shutdown_wait_for_slaves;
 Atomic_counter<uint32_t> slave_open_temp_tables;
 ulong thread_created;
-ulong back_log, connect_timeout, server_id;
+ulong back_log, connect_timeout, concurrency, server_id;
 ulong what_to_log;
 ulong slow_launch_time;
 ulong open_files_limit, max_binlog_size;

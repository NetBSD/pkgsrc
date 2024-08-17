$NetBSD: patch-sql_mysqld.cc,v 1.3 2024/08/17 00:06:23 nia Exp $

Add missing declaration of "concurrency".
Fixes build on illumos. From OmniOS CE.

--- sql/mysqld.cc.orig	2024-08-03 07:09:08.000000000 +0000
+++ sql/mysqld.cc
@@ -448,7 +448,7 @@ Atomic_counter<uint32_t> THD_count::coun
 bool shutdown_wait_for_slaves;
 Atomic_counter<uint32_t> slave_open_temp_tables;
 ulong thread_created;
-ulong back_log, connect_timeout, server_id;
+ulong back_log, connect_timeout, concurrency, server_id;
 ulong what_to_log;
 ulong slow_launch_time;
 ulong open_files_limit, max_binlog_size;

$NetBSD: patch-storage_rocksdb_rdb__io__watchdog.cc,v 1.1 2021/08/04 15:47:24 nia Exp $

If timer_t is an integer type, setting it to nullptr fails.

XXX: Using NULL turns it into a warning.

--- storage/rocksdb/rdb_io_watchdog.cc.orig	2020-01-26 20:43:56.000000000 +0000
+++ storage/rocksdb/rdb_io_watchdog.cc
@@ -111,7 +111,7 @@ void Rdb_io_watchdog::io_check_callback(
     sql_print_warning("Deleting the watchdog I/O timer failed with %d.", errno);
   }
 
-  m_io_check_watchdog_timer = nullptr;
+  m_io_check_watchdog_timer = NULL;
 
   RDB_MUTEX_UNLOCK_CHECK(m_reset_mutex);
 }

$NetBSD: patch-storage_rocksdb_rdb__io__watchdog.h,v 1.1 2023/07/10 22:55:49 nia Exp $

If timer_t is an integer type, setting it to nullptr fails.

XXX: Using NULL turns it into a warning.

--- storage/rocksdb/rdb_io_watchdog.h.orig	2020-01-26 20:43:56.000000000 +0000
+++ storage/rocksdb/rdb_io_watchdog.h
@@ -60,7 +60,7 @@ class Rdb_io_watchdog {
       ret = timer_delete(m_io_check_watchdog_timer);
 
       if (!ret) {
-        m_io_check_watchdog_timer = nullptr;
+        m_io_check_watchdog_timer = NULL;
       }
     }
 
@@ -68,7 +68,7 @@ class Rdb_io_watchdog {
       ret = timer_delete(m_io_check_timer);
 
       if (!ret) {
-        m_io_check_timer = nullptr;
+        m_io_check_timer = NULL;
       }
     }
 
@@ -93,8 +93,8 @@ class Rdb_io_watchdog {
 
  public:
   explicit Rdb_io_watchdog(std::vector<std::string> &&directories)
-      : m_io_check_timer(nullptr),
-        m_io_check_watchdog_timer(nullptr),
+      : m_io_check_timer(NULL),
+        m_io_check_watchdog_timer(NULL),
         m_io_in_progress(false),
         m_dirs_to_check(std::move(directories)),
         m_buf(nullptr) {

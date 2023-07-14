$NetBSD: patch-pdns_lock.hh,v 1.1 2023/07/14 11:49:26 nia Exp $

lock.hh:235:18: error: 'runtime_error' is not a member of 'std'
  235 |       throw std::runtime_error("Trying to access data protected by a mutex while the lock has not been acquired");
      |                  ^~~~~~~~~~~~~
lock.hh:25:1: note: 'std::runtime_error' is defined in header '<stdexcept>'; did you forget to '#include <stdexcept>'?
   24 | #include <shared_mutex>
  +++ |+#include <stdexcept>

--- pdns/lock.hh.orig	2022-12-08 18:36:25.000000000 +0000
+++ pdns/lock.hh
@@ -22,6 +22,7 @@
 #pragma once
 #include <mutex>
 #include <shared_mutex>
+#include <stdexcept>
 
 /*
   This file provides several features around locks:

$NetBSD: patch-sdk_src_file__service_file__flusher.cpp,v 1.1 2026/10/30 10:50:19 kikadf Exp $

* Cap the deadline. time_point::max() overflows without pthread_cond_clockwait,
  lwp_park returns with EINVAL and the wait loop spins

--- sdk/src/file_service/file_flusher.cpp.orig	2026-10-07 13:39:33.000000000 +0000
+++ sdk/src/file_service/file_flusher.cpp
@@ -103,12 +103,14 @@ void FileFlusher::loop()
     // Called to determine how long we should sleep for.
     auto nextWakeup = [this]()
     {
+        const auto limit = steady_clock::now() + std::chrono::hours(24);
+
         // Sleep until the next scheduled flush.
         if (!mQueue.empty())
-            return mQueue.front()->second.mScheduled;
+            return std::min(mQueue.front()->second.mScheduled, limit);
 
         // Sleep forever.
-        return steady_clock::time_point::max();
+        return limit;
     }; // nextWake
 
     // Acquire lock.

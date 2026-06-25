$NetBSD: patch-src_util_thread__runner.h,v 1.1 2026/06/25 08:16:54 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/thread_runner.h.orig	2026-06-25 07:57:05.592665777 +0000
+++ src/util/thread_runner.h
@@ -35,6 +35,7 @@
 #include <functional>
 #include <mutex>
 #include <pthread.h>
+#include <string.h>
 #include <thread>
 
 using ThreadProc = std::function<void(void* target)>;
@@ -191,7 +192,7 @@ class ThreadRunner : public ThreadExecutor { (protecte
             this);
 
         if (ret != 0) {
-            log_error("Could not start thread {}: {}", threadName, std::strerror(ret));
+            log_error("Could not start thread {}: {}", threadName, strerror(ret));
         } else {
             threadRunning = true;
         }

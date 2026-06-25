$NetBSD: patch-src_util_thread__executor.cc,v 1.1 2026/06/25 08:16:54 wiz Exp $

Fix build.
https://github.com/gerbera/gerbera/issues/3897

--- src/util/thread_executor.cc.orig	2026-06-25 08:08:22.982910419 +0000
+++ src/util/thread_executor.cc
@@ -53,7 +53,7 @@ void ThreadExecutor::startThread()
         this);
 
     if (ret != 0) {
-        log_error("Could not start thread: {}", std::strerror(ret));
+        log_error("Could not start thread: {}", strerror(ret));
     } else {
         threadRunning = true;
     }

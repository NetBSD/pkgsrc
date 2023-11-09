$NetBSD: patch-server_red-worker.cpp,v 1.1 2023/11/09 12:15:50 adam Exp $

Add NetBSD support.

--- server/red-worker.cpp.orig	2023-11-09 11:45:22.496015555 +0000
+++ server/red-worker.cpp
@@ -1049,7 +1049,9 @@ bool red_worker_run(RedWorker *worker)
 #ifndef _WIN32
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, nullptr);
 #endif
-#if !defined(__APPLE__)
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#elif !defined(__APPLE__)
     pthread_setname_np(worker->thread, "SPICE Worker");
 #endif
 

$NetBSD: patch-server_red-worker.c,v 1.3 2021/01/05 15:14:39 jperkin Exp $

Add NetBSD support.

--- server/red-worker.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/red-worker.c
@@ -1159,7 +1159,11 @@ bool red_worker_run(RedWorker *worker)
 #ifndef _WIN32
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, NULL);
 #endif
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#elif !defined(__sun)
     pthread_setname_np(worker->thread, "SPICE Worker");
+#endif
 
     return r == 0;
 }

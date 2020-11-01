$NetBSD: patch-server_red-worker.c,v 1.2 2020/11/01 19:36:37 maya Exp $

Add NetBSD support.

--- server/red-worker.c.orig	2019-04-30 08:51:11.000000000 +0000
+++ server/red-worker.c
@@ -1159,7 +1159,11 @@ bool red_worker_run(RedWorker *worker)
 #ifndef _WIN32
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, NULL);
 #endif
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#else
     pthread_setname_np(worker->thread, "SPICE Worker");
+#endif
 
     return r == 0;
 }

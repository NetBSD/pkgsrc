$NetBSD: patch-server_red-worker.c,v 1.1 2020/02/06 21:57:42 kamil Exp $

Add NetBSD support.

--- server/red-worker.c.orig	2019-04-30 08:51:11.000000000 +0000
+++ server/red-worker.c
@@ -1161,7 +1161,11 @@ bool red_worker_run(RedWorker *worker)
         spice_error("create thread failed %d", r);
     }
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, NULL);
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#else
     pthread_setname_np(worker->thread, "SPICE Worker");
+#endif
 
     return r == 0;
 }

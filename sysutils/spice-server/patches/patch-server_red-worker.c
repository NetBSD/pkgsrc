$NetBSD: patch-server_red-worker.c,v 1.4 2021/04/06 23:43:40 khorben Exp $

Add NetBSD support.

--- server/red-worker.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/red-worker.c
@@ -1119,6 +1119,9 @@ static void *red_worker_main(void *arg)
 {
     RedWorker *worker = arg;
 
+#if defined(__APPLE__)
+    pthread_setname_np("SPICE Worker");
+#endif
     spice_debug("begin");
     SPICE_VERIFY(MAX_PIPE_SIZE > WIDE_CLIENT_ACK_WINDOW &&
            MAX_PIPE_SIZE > NARROW_CLIENT_ACK_WINDOW); //ensure wakeup by ack message
@@ -1159,7 +1162,11 @@ bool red_worker_run(RedWorker *worker)
 #ifndef _WIN32
     pthread_sigmask(SIG_SETMASK, &curr_sig_mask, NULL);
 #endif
+#if defined(__NetBSD__)
+    pthread_setname_np(worker->thread, "%s", (void *)"SPICE Worker");
+#elif !defined(__sun) && !defined(__APPLE__)
     pthread_setname_np(worker->thread, "SPICE Worker");
+#endif
 
     return r == 0;
 }

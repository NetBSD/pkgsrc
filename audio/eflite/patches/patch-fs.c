$NetBSD: patch-fs.c,v 1.1 2024/02/25 22:00:09 wiz Exp $

Remove useless operator (typo)

--- fs.c.orig	2024-02-25 17:04:42.792873829 +0000
+++ fs.c
@@ -902,7 +902,7 @@ static int s_clear(synth_t *s)
   {
     wave_thread_cancel = 1;
 #ifdef DO_WAVE_CANCEL
--   pthread_cancel(wave_thread);
+    pthread_cancel(wave_thread);
 #endif
     pthread_cond_signal(&wave_condition); // necessary because we inhibit cancellation while waiting
   }

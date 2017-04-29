$NetBSD: patch-src_mpid_ch3_channels_nemesis_src_ch3__init.c,v 1.1 2017/04/29 18:18:52 adam Exp $

Use pthread_mutexattr_setpshared() only when available.

--- src/mpid/ch3/channels/nemesis/src/ch3_init.c.orig	2017-04-29 16:30:18.534262462 +0000
+++ src/mpid/ch3/channels/nemesis/src/ch3_init.c
@@ -52,6 +52,7 @@ static int split_type(MPID_Comm * comm_p
 
 int MPIDI_CH3I_Shm_supported(void)
 {
+#ifdef _POSIX_THREAD_PROCESS_SHARED
     int mutex_err;
     pthread_mutexattr_t attr;
 
@@ -63,6 +64,9 @@ int MPIDI_CH3I_Shm_supported(void)
     pthread_mutexattr_destroy(&attr);
 
     return !mutex_err;
+#else
+    return 0;
+#endif
 }
 
 static MPID_CommOps comm_fns = {

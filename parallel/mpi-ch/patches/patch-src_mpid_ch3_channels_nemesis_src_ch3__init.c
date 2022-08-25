$NetBSD: patch-src_mpid_ch3_channels_nemesis_src_ch3__init.c,v 1.2 2022/08/25 21:46:53 thor Exp $

Use pthread_mutexattr_setpshared() only when available.

--- src/mpid/ch3/channels/nemesis/src/ch3_init.c.orig	2021-12-16 16:59:29.000000000 +0000
+++ src/mpid/ch3/channels/nemesis/src/ch3_init.c
@@ -62,6 +62,7 @@ static int split_type(MPIR_Comm * user_c
 
 int MPIDI_CH3I_Shm_supported(void)
 {
+#ifdef _POSIX_THREAD_PROCESS_SHARED
     int mutex_err;
     pthread_mutexattr_t attr;
 
@@ -73,6 +74,9 @@ int MPIDI_CH3I_Shm_supported(void)
     pthread_mutexattr_destroy(&attr);
 
     return !mutex_err;
+#else
+    return 0;
+#endif
 }
 
 static MPIR_Commops comm_fns = {

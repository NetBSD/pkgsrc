$NetBSD: patch-src_mpid_ch3_channels_nemesis_include_mpidi_ch3_impl.h,v 1.2 2017/04/29 18:18:52 adam Exp $

Use pthread_mutexattr_setpshared() only when available.

--- src/mpid/ch3/channels/nemesis/include/mpidi_ch3_impl.h.orig	2015-11-10 02:39:01.000000000 +0000
+++ src/mpid/ch3/channels/nemesis/include/mpidi_ch3_impl.h
@@ -106,6 +106,7 @@ int MPIDI_CH3_SHM_Win_free(MPID_Win **wi
                              "**pthread_unlock %s", strerror(pt_err));                  \
     } while (0)
 
+#ifdef _POSIX_THREAD_PROCESS_SHARED
 #define MPIDI_CH3I_SHM_MUTEX_INIT(win_ptr)                                              \
     do {                                                                                \
         int pt_err;                                                                     \
@@ -124,6 +125,23 @@ int MPIDI_CH3_SHM_Win_free(MPID_Win **wi
         MPIR_ERR_CHKANDJUMP1(pt_err, mpi_errno, MPI_ERR_OTHER, "**pthread_mutex",       \
                              "**pthread_mutex %s", strerror(pt_err));                   \
     } while (0);
+#else
+#define MPIDI_CH3I_SHM_MUTEX_INIT(win_ptr)                                              \
+    do {                                                                                \
+        int pt_err;                                                                     \
+        pthread_mutexattr_t attr;                                                       \
+                                                                                        \
+        pt_err = pthread_mutexattr_init(&attr);                                         \
+        MPIR_ERR_CHKANDJUMP1(pt_err, mpi_errno, MPI_ERR_OTHER, "**pthread_mutex",       \
+                             "**pthread_mutex %s", strerror(pt_err));                   \
+        pt_err = pthread_mutex_init((win_ptr)->shm_mutex, &attr);                       \
+        MPIR_ERR_CHKANDJUMP1(pt_err, mpi_errno, MPI_ERR_OTHER, "**pthread_mutex",       \
+                             "**pthread_mutex %s", strerror(pt_err));                   \
+        pt_err = pthread_mutexattr_destroy(&attr);                                      \
+        MPIR_ERR_CHKANDJUMP1(pt_err, mpi_errno, MPI_ERR_OTHER, "**pthread_mutex",       \
+                             "**pthread_mutex %s", strerror(pt_err));                   \
+    } while (0);
+#endif
 
 #define MPIDI_CH3I_SHM_MUTEX_DESTROY(win_ptr)                                           \
     do {                                                                                \

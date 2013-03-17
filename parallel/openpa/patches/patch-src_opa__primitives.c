$NetBSD: patch-src_opa__primitives.c,v 1.1 2013/03/17 14:43:48 asau Exp $

--- src/opa_primitives.c.orig	2012-12-05 01:25:36.000000000 +0000
+++ src/opa_primitives.c
@@ -14,6 +14,8 @@
 #include <pthread.h>
 #include <opa_primitives.h>
 
+#include <unistd.h> /* for _POSIX_THREAD_PROCESS_SHARED */
+
 pthread_mutex_t *OPA_emulation_lock = NULL;
 
 int OPA_Interprocess_lock_init(OPA_emulation_ipl_t *shm_lock, int isLeader)
@@ -27,7 +29,9 @@ int OPA_Interprocess_lock_init(OPA_emula
          * shared memory as well. This is required for some compilers
          * (such as SUN Studio) that don't enable it by default. */
         if (pthread_mutexattr_init(&attr) ||
+#ifdef _POSIX_THREAD_PROCESS_SHARED
             pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED) ||
+#endif
             pthread_mutex_init(OPA_emulation_lock, &attr))
             mpi_errno = 16; /* MPI_ERR_INTERN */
     }

$NetBSD: patch-iozone.c,v 1.1 2022/05/28 11:39:57 adam Exp $

Support DragonFly.
pthread_barrierattr_setpshared() is hidden on NetBSD.

--- iozone.c.orig	2022-03-16 20:00:50.000000000 +0000
+++ iozone.c
@@ -475,6 +475,9 @@ struct piovec piov[PVECMAX];
 struct iovec piov[PVECMAX];
 #define piov_base iov_base
 #define piov_len iov_len
+#if defined (__DragonFly__)
+#define DFLY_VECTOR_OFFSET
+#endif
 #endif
 
 #endif
@@ -3971,13 +3974,17 @@ throughput_test()
 	if(use_thread)
 	{
 		barrier = (pthread_barrier_t*)alloc_mem(sizeof(pthread_barrier_t), 0); // Not shared
+#ifndef __NetBSD__
 		pthread_barrierattr_setpshared(&barrier_attr, PTHREAD_PROCESS_PRIVATE);
+#endif
 		pthread_barrier_init(barrier, &barrier_attr, num_child);
 	}
 	else
 	{
 		barrier = (pthread_barrier_t*)alloc_mem(sizeof(pthread_barrier_t), 1); // Shared
+#ifndef __NetBSD__
 		pthread_barrierattr_setpshared(&barrier_attr, PTHREAD_PROCESS_SHARED);
+#endif
 		pthread_barrier_init(barrier, &barrier_attr, num_child);
 	}
 
@@ -11429,7 +11436,7 @@ long long *data1,*data2;
 					purgeit(piov[xx].piov_base,reclen);
 			}
 			if(pwritev(fd, piov,numvecs
-#ifndef PER_VECTOR_OFFSET
+#if defined(PER_VECTOR_OFFSET) || defined(DFLY_VECTOR_OFFSET)
 				, list_off[0]
 #endif
 				) != (reclen*numvecs))
@@ -11759,7 +11766,7 @@ long long *data1,*data2;
 				   purgeit(piov[xx].piov_base,reclen);
 			}
 			if(preadv(fd, piov, numvecs
-#ifndef PER_VECTOR_OFFSET
+#if defined(PER_VECTOR_OFFSET) || defined(DFLY_VECTOR_OFFSET)
 				, list_off[0]
 #endif
 				) != (numvecs * reclen))

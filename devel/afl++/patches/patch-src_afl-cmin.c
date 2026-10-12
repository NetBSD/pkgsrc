$NetBSD: patch-src_afl-cmin.c,v 1.1 2026/10/12 21:41:43 wiz Exp $

NetBSD does not provide these functions.

--- src/afl-cmin.c.orig	2026-10-12 21:35:09.457696516 +0000
+++ src/afl-cmin.c
@@ -274,13 +274,17 @@ static void queue_init(u64 capacity) {
 
   pthread_mutexattr_t mattr;
   pthread_mutexattr_init(&mattr);
+#if !defined(__NetBSD__)
   pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
+#endif
   pthread_mutex_init(&queue->mutex, &mattr);
   pthread_mutexattr_destroy(&mattr);
 
   pthread_condattr_t cattr;
   pthread_condattr_init(&cattr);
+#if !defined(__NetBSD__)
   pthread_condattr_setpshared(&cattr, PTHREAD_PROCESS_SHARED);
+#endif
   pthread_cond_init(&queue->cond_read, &cattr);
   pthread_cond_init(&queue->cond_write, &cattr);
   pthread_condattr_destroy(&cattr);

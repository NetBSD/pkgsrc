$NetBSD: patch-unix_mpthreadport.c,v 1.1 2017/11/29 15:13:32 hauke Exp $

NetBSD does not (yet) #define PTHREAD_STACK_MIN

--- unix/mpthreadport.c.orig	2017-08-23 01:50:11.000000000 +0000
+++ unix/mpthreadport.c
@@ -140,11 +140,13 @@ void mp_thread_create(void *(*entry)(voi
         *stack_size = 8192 * BYTES_PER_WORD;
     }
 
+#ifdef PTHREAD_STACK_MIN	/* NetBSD */
     // minimum stack size is set by pthreads
     if (*stack_size < PTHREAD_STACK_MIN) {
         *stack_size = PTHREAD_STACK_MIN;
     }
-
+#endif /* PTHREAD_STACK_MIN */
+    
     // set thread attributes
     pthread_attr_t attr;
     int ret = pthread_attr_init(&attr);

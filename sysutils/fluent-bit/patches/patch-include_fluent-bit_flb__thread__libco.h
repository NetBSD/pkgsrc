$NetBSD: patch-include_fluent-bit_flb__thread__libco.h,v 1.1 2020/04/20 00:45:56 joerg Exp $

NetBSD doesn't define THREAD_STACK_MIN, so pick an arbitrary 16 pages.

--- include/fluent-bit/flb_thread_libco.h.orig	2018-05-21 16:59:19.000000000 +0000
+++ include/fluent-bit/flb_thread_libco.h
@@ -54,7 +54,12 @@ struct flb_thread {
     void (*cb_destroy) (void *);
 };
 
+#if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#include <machine/vmparam.h>
+#define FLB_THREAD_STACK_SIZE      (16 * PAGE_SIZE)
+#else
 #define FLB_THREAD_STACK_SIZE      ((3 * PTHREAD_STACK_MIN) / 2)
+#endif
 #define FLB_THREAD_DATA(th)        (((char *) th) + sizeof(struct flb_thread))
 
 FLB_EXPORT pthread_key_t flb_thread_key;

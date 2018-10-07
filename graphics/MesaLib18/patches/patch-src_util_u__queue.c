$NetBSD: patch-src_util_u__queue.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/util/u_queue.c.orig	2018-01-09 16:03:44.000000000 +0000
+++ src/util/u_queue.c
@@ -40,11 +40,22 @@ static once_flag atexit_once_flag = ONCE
 static struct list_head queue_list;
 static mtx_t exit_mutex = _MTX_INITIALIZER_NP;
 
+#if defined(HAVE_NOATEXIT)
+static int global_init_called = 0;
+
+static void __attribute__((__destructor__))
+#else
 static void
+#endif
 atexit_handler(void)
 {
    struct util_queue *iter;
 
+#if defined(HAVE_NOATEXIT)
+   if (!global_init_called)
+      return;
+#endif
+
    mtx_lock(&exit_mutex);
    /* Wait for all queues to assert idle. */
    LIST_FOR_EACH_ENTRY(iter, &queue_list, head) {
@@ -57,7 +68,11 @@ static void
 global_init(void)
 {
    LIST_INITHEAD(&queue_list);
+#if defined(HAVE_NOATEXIT)
+   global_init_called = 1;
+#else
    atexit(atexit_handler);
+#endif
 }
 
 static void

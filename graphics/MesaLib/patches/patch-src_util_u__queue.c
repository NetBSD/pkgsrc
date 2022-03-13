$NetBSD: patch-src_util_u__queue.c,v 1.3 2022/03/13 15:50:05 tnn Exp $

atexit() is not a good idea in shared libraries.

FreeBSD reported atexit bug for 10.6:
https://bugs.freedesktop.org/show_bug.cgi?id=91869

--- src/util/u_queue.c.orig	2021-07-14 20:04:59.260044300 +0000
+++ src/util/u_queue.c
@@ -58,11 +58,22 @@ static once_flag atexit_once_flag = ONCE
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
@@ -75,7 +86,11 @@ static void
 global_init(void)
 {
    list_inithead(&queue_list);
+#if defined(HAVE_NOATEXIT)
+   global_init_called = 1;
+#else
    atexit(atexit_handler);
+#endif
 }
 
 static void

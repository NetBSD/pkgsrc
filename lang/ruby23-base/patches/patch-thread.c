$NetBSD: patch-thread.c,v 1.1 2015/12/30 14:59:42 taca Exp $

--- thread.c.orig	2015-12-09 00:38:32.000000000 +0000
+++ thread.c
@@ -466,8 +466,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
     volatile int sleeping = 0;
 
     if (vm->main_thread != th) {

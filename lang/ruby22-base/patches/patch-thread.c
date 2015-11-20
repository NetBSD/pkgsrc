$NetBSD: patch-thread.c,v 1.1 2015/11/20 14:31:59 joerg Exp $

--- thread.c.orig	2015-11-16 15:03:41.000000000 +0000
+++ thread.c
@@ -420,8 +420,8 @@ rb_threadptr_unlock_all_locking_mutexes(
 void
 rb_thread_terminate_all(void)
 {
-    rb_thread_t *th = GET_THREAD(); /* main thread */
-    rb_vm_t *vm = th->vm;
+    rb_thread_t *volatile th = GET_THREAD(); /* main thread */
+    rb_vm_t *volatile vm = th->vm;
 
     if (vm->main_thread != th) {
 	rb_bug("rb_thread_terminate_all: called by child thread (%p, %p)",

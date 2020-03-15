$NetBSD: patch-thread__pthread.c,v 1.1 2020/03/15 15:26:22 taca Exp $

* Avoid pass "const char *" to SET_ANOTHER_THREAD_NAME();
  pthread_setname_np().

--- thread_pthread.c.orig	2018-12-20 00:07:19.000000000 +0000
+++ thread_pthread.c
@@ -1667,7 +1667,7 @@ static VALUE
 native_set_another_thread_name(rb_nativethread_id_t thread_id, VALUE name)
 {
 #ifdef SET_ANOTHER_THREAD_NAME
-    const char *s = "";
+    char *s = "";
     if (!NIL_P(name)) s = RSTRING_PTR(name);
     SET_ANOTHER_THREAD_NAME(thread_id, s);
 #endif

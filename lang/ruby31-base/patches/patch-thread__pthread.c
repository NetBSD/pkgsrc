$NetBSD: patch-thread__pthread.c,v 1.1 2022/01/16 13:57:10 taca Exp $

* Avoid pass "const char *" to SET_ANOTHER_THREAD_NAME();
  pthread_setname_np().

--- thread_pthread.c.orig	2020-12-08 09:02:31.000000000 +0000
+++ thread_pthread.c
@@ -1648,7 +1648,7 @@ native_set_another_thread_name(rb_native
 {
 #if defined SET_ANOTHER_THREAD_NAME || defined SET_CURRENT_THREAD_NAME
     char buf[THREAD_NAME_MAX];
-    const char *s = "";
+    char *s = "";
 # if !defined SET_ANOTHER_THREAD_NAME
     if (!pthread_equal(pthread_self(), thread_id)) return;
 # endif

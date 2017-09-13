$NetBSD: patch-common_threads.c,v 1.2 2017/09/13 08:08:22 wiz Exp $

Adjust usage of pthread_setname_np(3).

--- common/threads.c.orig	2017-07-30 05:09:21.000000000 +0000
+++ common/threads.c
@@ -501,8 +501,12 @@ void althrd_setname(althrd_t thr, const 
     if(althrd_equal(thr, althrd_current()))
         pthread_setname_np(name);
 #else
+#if defined(__NetBSD__)
+    pthread_setname_np(thr, "%s", (void *)name);
+#else
     pthread_setname_np(thr, name);
 #endif
+#endif
 #elif defined(HAVE_PTHREAD_SET_NAME_NP)
     pthread_set_name_np(thr, name);
 #else

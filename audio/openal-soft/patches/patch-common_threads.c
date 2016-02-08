$NetBSD: patch-common_threads.c,v 1.1 2016/02/08 01:53:48 markd Exp $

Adjust usage of pthread_setname_np(3).

--- common/threads.c.orig	2016-01-25 04:12:39.000000000 +0100
+++ common/threads.c	2016-01-29 18:13:41.000000000 +0100
@@ -501,8 +501,12 @@
     if(althrd_equal(thr, althrd_current()))
         pthread_setname_np(name);
 #else
+#if defined(__NetBSD__)
+    pthread_setname_np(thr, "%s", name);
+#else
     pthread_setname_np(thr, name);
 #endif
+#endif
 #elif defined(HAVE_PTHREAD_SET_NAME_NP)
     pthread_set_name_np(thr, name);
 #else

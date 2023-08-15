$NetBSD: patch-osdep_threads.c,v 1.1 2023/08/15 19:17:10 leot Exp $

Add support for NetBSD.

--- osdep/threads.c.orig	2023-07-23 17:10:36.000000000 +0000
+++ osdep/threads.c
@@ -51,6 +51,8 @@ void mpthread_set_name(const char *name)
     pthread_set_name_np(pthread_self(), tname);
 #elif HAVE_OSX_THREAD_NAME
     pthread_setname_np(tname);
+#elif HAVE_NETBSD_THREAD_NAME
+    pthread_setname_np(pthread_self(), "%s", tname);
 #endif
 }
 

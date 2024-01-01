$NetBSD: patch-osdep_threads-posix.h,v 1.1 2024/01/01 15:50:14 leot Exp $

Add support for NetBSD.

--- osdep/threads-posix.h.orig	2023-12-31 11:13:03.078250654 +0000
+++ osdep/threads-posix.h
@@ -232,6 +232,8 @@ static inline void mp_thread_set_name(co
     pthread_set_name_np(pthread_self(), name);
 #elif HAVE_OSX_THREAD_NAME
     pthread_setname_np(name);
+#elif HAVE_NETBSD_THREAD_NAME
+    pthread_setname_np(pthread_self(), "%s", name);
 #endif
 }
 

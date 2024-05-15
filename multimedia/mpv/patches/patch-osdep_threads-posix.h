$NetBSD: patch-osdep_threads-posix.h,v 1.2 2024/05/15 20:37:20 wiz Exp $

Add support for NetBSD.

--- osdep/threads-posix.h.orig	2024-04-17 19:18:44.000000000 +0000
+++ osdep/threads-posix.h
@@ -237,6 +237,8 @@ static inline void mp_thread_set_name(co
     pthread_set_name_np(pthread_self(), name);
 #elif HAVE_MAC_THREAD_NAME
     pthread_setname_np(name);
+#elif HAVE_NETBSD_THREAD_NAME
+    pthread_setname_np(pthread_self(), "%s", name);
 #endif
 }
 

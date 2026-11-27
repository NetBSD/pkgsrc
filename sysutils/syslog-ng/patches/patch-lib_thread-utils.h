$NetBSD: patch-lib_thread-utils.h,v 1.1 2026/11/27 11:01:43 adam Exp $

Support NetBSD.

--- lib/thread-utils.h.orig	2026-11-27 06:22:50.109270666 +0000
+++ lib/thread-utils.h
@@ -67,6 +67,8 @@ set_thread_name(const gchar *name)
 #ifndef _WIN32
 # if defined(__APPLE__)
   pthread_setname_np(name);
+# elif defined(__NetBSD__)
+  pthread_setname_np(pthread_self(), name, NULL);
 # else
   pthread_setname_np(pthread_self(), name);
 # endif

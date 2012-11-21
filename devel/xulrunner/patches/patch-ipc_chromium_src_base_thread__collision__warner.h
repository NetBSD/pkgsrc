$NetBSD: patch-ipc_chromium_src_base_thread__collision__warner.h,v 1.1 2012/11/21 15:26:50 ryoon Exp $

* Fix debug build, patch is provided from martin@

--- ipc/chromium/src/base/thread_collision_warner.h.orig	2012-10-23 19:42:37.000000000 +0000
+++ ipc/chromium/src/base/thread_collision_warner.h
@@ -101,7 +101,7 @@
 // Defines a class member that acts like a mutex. It is used only as a
 // verification tool.
 #define DFAKE_MUTEX(obj) \
-     mutable base::ThreadCollisionWarner obj
+     mutable base::ThreadCollisionWarner obj;
 // Asserts the call is never called simultaneously in two threads. Used at
 // member function scope.
 #define DFAKE_SCOPED_LOCK(obj) \

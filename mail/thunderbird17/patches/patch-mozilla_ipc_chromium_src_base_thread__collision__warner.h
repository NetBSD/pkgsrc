$NetBSD: patch-mozilla_ipc_chromium_src_base_thread__collision__warner.h,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/ipc/chromium/src/base/thread_collision_warner.h.orig	2012-11-19 22:42:22.000000000 +0000
+++ mozilla/ipc/chromium/src/base/thread_collision_warner.h
@@ -101,7 +101,7 @@
 // Defines a class member that acts like a mutex. It is used only as a
 // verification tool.
 #define DFAKE_MUTEX(obj) \
-     mutable base::ThreadCollisionWarner obj
+     mutable base::ThreadCollisionWarner obj;
 // Asserts the call is never called simultaneously in two threads. Used at
 // member function scope.
 #define DFAKE_SCOPED_LOCK(obj) \

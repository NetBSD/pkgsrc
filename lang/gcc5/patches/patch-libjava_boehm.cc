$NetBSD: patch-libjava_boehm.cc,v 1.1 2015/07/16 12:03:36 ryoon Exp $

--- libjava/boehm.cc.orig	2014-05-20 18:02:20.000000000 +0000
+++ libjava/boehm.cc
@@ -748,7 +748,7 @@ _Jv_GCAttachThread ()
   // only actually works if pthread_getattr_np is defined.
   // FIXME: until gc7 it is simpler to disable this on solaris.
 #if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS) \
-    && !defined(GC_WIN32_THREADS)
+    && !defined(__NetBSD__) && !defined(GC_WIN32_THREADS)
   GC_register_my_thread ();
 #endif
 }
@@ -757,7 +757,7 @@ void
 _Jv_GCDetachThread ()
 {
 #if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS) \
-    && !defined(GC_WIN32_THREADS)
+    && !defined(__NetBSD__) && !defined(GC_WIN32_THREADS)
   GC_unregister_my_thread ();
 #endif
 }

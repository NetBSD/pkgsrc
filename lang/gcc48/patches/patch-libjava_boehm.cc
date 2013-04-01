$NetBSD: patch-libjava_boehm.cc,v 1.1 2013/04/01 21:06:17 wiz Exp $

Disable GC_register_my_thread and GC_unregister_my_thread on NetBSD as
the version of boehm-gc bundled with gcc does not support NetBSD threads.

--- libjava/boehm.cc.orig	2007-10-22 21:24:35.000000000 +0000
+++ libjava/boehm.cc
@@ -747,7 +747,8 @@ _Jv_GCAttachThread ()
   // The registration interface is only defined on posixy systems and
   // only actually works if pthread_getattr_np is defined.
   // FIXME: until gc7 it is simpler to disable this on solaris.
-#if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS)
+#if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS) \
+    && !defined(__NetBSD__)
   GC_register_my_thread ();
 #endif
 }
@@ -755,7 +756,8 @@ _Jv_GCAttachThread ()
 void
 _Jv_GCDetachThread ()
 {
-#if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS)
+#if defined(HAVE_PTHREAD_GETATTR_NP) && !defined(GC_SOLARIS_THREADS) \
+    && !defined(__NetBSD__)
   GC_unregister_my_thread ();
 #endif
 }

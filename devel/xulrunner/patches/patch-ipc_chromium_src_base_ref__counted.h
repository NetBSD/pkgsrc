$NetBSD: patch-ipc_chromium_src_base_ref__counted.h,v 1.1 2012/08/28 12:42:01 ryoon Exp $

--- ipc/chromium/src/base/ref_counted.h.orig	2012-08-08 20:20:07.000000000 +0000
+++ ipc/chromium/src/base/ref_counted.h
@@ -28,7 +28,7 @@ class RefCountedBase {
   bool in_dtor_;
 #endif
 
-  DFAKE_MUTEX(add_release_);
+  DFAKE_MUTEX(add_release_)
 
   DISALLOW_COPY_AND_ASSIGN(RefCountedBase);
 };

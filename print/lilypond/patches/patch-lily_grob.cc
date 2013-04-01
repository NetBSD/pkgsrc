$NetBSD: patch-lily_grob.cc,v 1.1 2013/04/01 12:20:47 joerg Exp $

Issue 3201.

--- lily/grob.cc.orig	2013-03-31 15:06:04.000000000 +0000
+++ lily/grob.cc
@@ -82,13 +82,16 @@ Grob::Grob (SCM basicprops)
 }
 
 Grob::Grob (Grob const &s)
-  : dim_cache_ (s.dim_cache_)
 {
   original_ = (Grob *) & s;
   self_scm_ = SCM_EOL;
 
   immutable_property_alist_ = s.immutable_property_alist_;
   mutable_property_alist_ = SCM_EOL;
+
+  for (Axis a = X_AXIS; a < NO_AXES; incr (a))
+    dim_cache_ [a] = s.dim_cache_ [a];
+
   interfaces_ = s.interfaces_;
   object_alist_ = SCM_EOL;
 

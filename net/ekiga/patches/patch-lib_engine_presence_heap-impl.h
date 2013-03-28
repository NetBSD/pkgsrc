$NetBSD: patch-lib_engine_presence_heap-impl.h,v 1.1 2013/03/28 21:34:51 joerg Exp $

--- lib/engine/presence/heap-impl.h.orig	2013-03-28 17:40:57.000000000 +0000
+++ lib/engine/presence/heap-impl.h
@@ -160,7 +160,7 @@ Ekiga::HeapImpl<PresentityType>::add_pre
 {
   presentity->questions.add_handler (questions.make_slot ());
 
-  add_object (presentity);
+  this->add_object (presentity);
 }
 
 template<typename PresentityType>

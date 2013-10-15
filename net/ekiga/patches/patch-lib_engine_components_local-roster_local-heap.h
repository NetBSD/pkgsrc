$NetBSD: patch-lib_engine_components_local-roster_local-heap.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/local-roster/local-heap.h.orig	2013-10-15 12:56:10.000000000 +0000
+++ lib/engine/components/local-roster/local-heap.h
@@ -199,7 +199,7 @@ namespace Local
 				      Ekiga::Form& result);
 
     Ekiga::ServiceCore &core;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
   };
 
   typedef gmref_ptr<Heap> HeapPtr;

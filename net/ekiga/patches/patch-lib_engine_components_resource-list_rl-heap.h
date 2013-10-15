$NetBSD: patch-lib_engine_components_resource-list_rl-heap.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-heap.h.orig	2013-10-15 12:56:47.000000000 +0000
+++ lib/engine/components/resource-list/rl-heap.h
@@ -49,7 +49,7 @@ namespace RL {
   public:
 
     Heap (Ekiga::ServiceCore& services_,
-	  std::tr1::shared_ptr<xmlDoc> doc_,
+	  shared_ptr<xmlDoc> doc_,
 	  xmlNodePtr node);
 
     /* name: the name of the Heap in the GUI
@@ -63,7 +63,7 @@ namespace RL {
      *
      */
     Heap (Ekiga::ServiceCore& core_,
-	  std::tr1::shared_ptr<xmlDoc> doc_,
+	  shared_ptr<xmlDoc> doc_,
 	  const std::string name_,
 	  const std::string root_,
 	  const std::string user_,
@@ -103,7 +103,7 @@ namespace RL {
     xmlNodePtr username;
     xmlNodePtr password;
 
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr list_node;
 
     std::map<PresentityPtr, std::list<sigc::connection> > presentities;

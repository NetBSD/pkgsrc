$NetBSD: patch-lib_engine_components_resource-list_rl-entry.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-entry.h.orig	2013-10-15 12:53:30.000000000 +0000
+++ lib/engine/components/resource-list/rl-entry.h
@@ -44,7 +44,14 @@
 
 #include <libxml/tree.h>
 
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using shared_ptr;
+#endif
 
 namespace RL {
 
@@ -58,7 +65,7 @@ namespace RL {
 	   gmref_ptr<XCAP::Path> path_,
 	   int pos,
 	   const std::string group,
-	   std::tr1::shared_ptr<xmlDoc> doc_,
+	   shared_ptr<xmlDoc> doc_,
 	   xmlNodePtr node_);
 
     ~Entry ();
@@ -96,7 +103,7 @@ namespace RL {
 
     std::set<std::string> groups;
 
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr node;
     xmlNodePtr name_node;
 

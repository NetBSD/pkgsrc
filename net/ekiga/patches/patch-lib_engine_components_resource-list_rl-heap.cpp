$NetBSD: patch-lib_engine_components_resource-list_rl-heap.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-heap.cpp.orig	2013-10-15 12:56:37.000000000 +0000
+++ lib/engine/components/resource-list/rl-heap.cpp
@@ -46,7 +46,7 @@
 #include "rl-heap.h"
 
 RL::Heap::Heap (Ekiga::ServiceCore& services_,
-		std::tr1::shared_ptr<xmlDoc> doc_,
+		shared_ptr<xmlDoc> doc_,
 		xmlNodePtr node_):
   services(services_),
   node(node_), name(NULL),
@@ -115,7 +115,7 @@ RL::Heap::Heap (Ekiga::ServiceCore& serv
 }
 
 RL::Heap::Heap (Ekiga::ServiceCore& services_,
-		std::tr1::shared_ptr<xmlDoc> doc_,
+		shared_ptr<xmlDoc> doc_,
 		const std::string name_,
 		const std::string root_,
 		const std::string user_,
@@ -286,9 +286,9 @@ RL::Heap::on_document_received (bool err
 void
 RL::Heap::parse_doc (std::string raw)
 {
-  doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
+  doc = shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
   if ( !doc)
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
   xmlNodePtr doc_root = xmlDocGetRootElement (doc.get ());
 
   if (doc_root == NULL

$NetBSD: patch-lib_engine_components_resource-list_rl-list.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-list.cpp.orig	2013-10-15 12:56:42.000000000 +0000
+++ lib/engine/components/resource-list/rl-list.cpp
@@ -82,7 +82,7 @@ public: // no need to make anything priv
 
   std::string group;
 
-  std::tr1::shared_ptr<xmlDoc> doc;
+  shared_ptr<xmlDoc> doc;
   xmlNodePtr node;
 
   xmlNodePtr name_node;
@@ -270,9 +270,9 @@ RL::ListImpl::on_xcap_answer (bool error
 
   } else {
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (value.c_str (), value.length ()), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlRecoverMemory (value.c_str (), value.length ()), xmlFreeDoc);
     if ( !doc)
-      doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+      doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
     node = xmlDocGetRootElement (doc.get ());
     if (node == NULL
 	|| node->name == NULL

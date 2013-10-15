$NetBSD: patch-lib_engine_components_resource-list_rl-cluster.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-cluster.cpp.orig	2013-10-15 12:56:25.000000000 +0000
+++ lib/engine/components/resource-list/rl-cluster.cpp
@@ -62,9 +62,9 @@ RL::Cluster::Cluster (Ekiga::ServiceCore
   if (c_raw != NULL) {
 
     const std::string raw = c_raw;
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
     if ( !doc)
-      doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+      doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
 
     xmlNodePtr root = xmlDocGetRootElement (doc.get ());
     if (root == NULL) {
@@ -85,7 +85,7 @@ RL::Cluster::Cluster (Ekiga::ServiceCore
 
   } else {
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
     xmlNodePtr root = xmlNewDocNode (doc.get (), NULL, BAD_CAST "list", NULL);
     xmlDocSetRootElement (doc.get (), root);
     add ("https://xcap.sipthor.net/xcap-root", "alice", "123", "alice@example.com", "XCAP Test", false); // FIXME: remove

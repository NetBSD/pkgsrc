$NetBSD: patch-lib_engine_components_local-roster_local-heap.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/local-roster/local-heap.cpp.orig	2013-10-15 12:55:57.000000000 +0000
+++ lib/engine/components/local-roster/local-heap.cpp
@@ -60,9 +60,9 @@ Local::Heap::Heap (Ekiga::ServiceCore &_
   if (c_raw != NULL) {
 
     const std::string raw = c_raw;
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
     if ( !doc)
-      doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+      doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
 
     root = xmlDocGetRootElement (doc.get ());
     if (root == NULL) {
@@ -83,7 +83,7 @@ Local::Heap::Heap (Ekiga::ServiceCore &_
   }
   else {
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
     root = xmlNewDocNode (doc.get (), NULL, BAD_CAST "list", NULL);
     xmlDocSetRootElement (doc.get (), root);
 

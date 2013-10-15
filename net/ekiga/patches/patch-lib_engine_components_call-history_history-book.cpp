$NetBSD: patch-lib_engine_components_call-history_history-book.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/call-history/history-book.cpp.orig	2013-10-15 13:03:14.000000000 +0000
+++ lib/engine/components/call-history/history-book.cpp
@@ -58,9 +58,9 @@ History::Book::Book (Ekiga::ServiceCore 
 
     const std::string raw = c_raw;
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
     if ( !doc)
-      doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+      doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
 
     root = xmlDocGetRootElement (doc.get ());
     if (root == NULL) {
@@ -80,7 +80,7 @@ History::Book::Book (Ekiga::ServiceCore 
     g_free (c_raw);
   } else {
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
     root = xmlNewDocNode (doc.get (), NULL, BAD_CAST "list", NULL);
     xmlDocSetRootElement (doc.get (), root);
   }
@@ -176,7 +176,7 @@ History::Book::clear ()
 
   remove_all_objects ();
 
-  doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+  doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
   root = xmlNewDocNode (doc.get (), NULL, BAD_CAST "list", NULL);
   xmlDocSetRootElement (doc.get (), root);
 

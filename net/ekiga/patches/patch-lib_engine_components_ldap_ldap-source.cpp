$NetBSD: patch-lib_engine_components_ldap_ldap-source.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/ldap/ldap-source.cpp.orig	2013-10-15 12:55:21.000000000 +0000
+++ lib/engine/components/ldap/ldap-source.cpp
@@ -58,9 +58,9 @@ OPENLDAP::Source::Source (Ekiga::Service
 
     const std::string raw = c_raw;
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlRecoverMemory (raw.c_str (), raw.length ()), xmlFreeDoc);
     if ( !doc)
-      doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+      doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
 
     root = xmlDocGetRootElement (doc.get ());
 
@@ -83,7 +83,7 @@ OPENLDAP::Source::Source (Ekiga::Service
     g_free (c_raw);
   } else {
 
-    doc = std::tr1::shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
+    doc = shared_ptr<xmlDoc> (xmlNewDoc (BAD_CAST "1.0"), xmlFreeDoc);
     root = xmlNewDocNode (doc.get (), NULL, BAD_CAST "list", NULL);
     xmlDocSetRootElement (doc.get (), root);
 

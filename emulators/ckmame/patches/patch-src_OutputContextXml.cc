$NetBSD: patch-src_OutputContextXml.cc,v 1.1 2026/02/20 11:08:31 wiz Exp $

Fix build with libxml2 2.15.
https://github.com/nih-at/ckmame/commit/4cffb0c02f9fa79a158d46a40d08894a3ef662ba

--- src/OutputContextXml.cc.orig	2026-02-20 11:05:45.838572775 +0000
+++ src/OutputContextXml.cc
@@ -57,7 +57,7 @@ OutputContextXml::OutputContextXml(const std::string &
     }
 
     doc = xmlNewDoc(xml_string("1.0"));
-    doc->encoding = xml_string(strdup("UTF-8"));
+    doc->encoding = reinterpret_cast<xmlChar *>(strdup("UTF-8"));
     xmlCreateIntSubset(doc, xml_string("datafile"), xml_string("-//Logiqx//DTD ROM Management Datafile//EN"), xml_string("http://www.logiqx.com/Dats/datafile.dtd"));
     root = xmlNewNode(nullptr, xml_string("datafile"));
     xmlDocSetRootElement(doc, root);

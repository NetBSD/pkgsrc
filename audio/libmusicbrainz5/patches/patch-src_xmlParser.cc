$NetBSD: patch-src_xmlParser.cc,v 1.1 2024/02/01 08:50:01 wiz Exp $

Fix build with libxml2 2.12.
https://github.com/metabrainz/libmusicbrainz/commit/9ba00067a15479a52262a5126bcb6889da5884b7
https://github.com/metabrainz/libmusicbrainz/commit/558c9ba0e6d702d5c877f75be98176f57abf1b02

--- src/xmlParser.cc.orig	2024-02-01 08:48:39.967034933 +0000
+++ src/xmlParser.cc
@@ -30,6 +30,7 @@
 
 #include <cstring>
 #include <libxml/tree.h>
+#include <libxml/parser.h>
 
 XMLResults::XMLResults()
     : line(0),
@@ -56,7 +57,7 @@ XMLNode *XMLRootNode::parseFile(const st
 
     doc = xmlParseFile(filename.c_str());
     if ((doc == NULL) && (results != NULL)) {
-        xmlErrorPtr error = xmlGetLastError();
+        const xmlError * error = xmlGetLastError();
         results->message = error->message;
         results->line = error->line;
         results->code = error->code;
@@ -71,7 +72,7 @@ XMLNode *XMLRootNode::parseString(const 
 
     doc = xmlParseMemory(xml.c_str(), xml.length());
     if ((doc == NULL) && (results != NULL)) {
-        xmlErrorPtr error = xmlGetLastError();
+        const xmlError * error = xmlGetLastError();
         results->message = error->message;
         results->line = error->line;
         results->code = error->code;

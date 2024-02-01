$NetBSD: patch-src_xml.h,v 1.1 2024/02/01 09:33:08 wiz Exp $

--- src/xml.h.orig	2024-02-01 09:30:08.504957542 +0000
+++ src/xml.h
@@ -6,6 +6,7 @@
 #define XML_H
 
 #include <string>
+#include <libxml/parser.h>
 #include <libxml/xmlmemory.h>
 
 xmlDocPtr xmlParse(const char *filename);

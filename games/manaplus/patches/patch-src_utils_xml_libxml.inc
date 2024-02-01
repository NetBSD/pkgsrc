$NetBSD: patch-src_utils_xml_libxml.inc,v 1.1 2024/02/01 08:57:16 wiz Exp $

Fix build with libxml2 2.12.
https://gitlab.com/manaplus/manaplus/-/issues/33

--- src/utils/xml/libxml.inc.orig	2024-02-01 08:54:19.624180650 +0000
+++ src/utils/xml/libxml.inc
@@ -24,6 +24,7 @@
 
 #ifdef ENABLE_LIBXML
 
+#include <libxml/parser.h>
 #include <libxml/xmlwriter.h>
 
 __XML_XMLWRITER_H__

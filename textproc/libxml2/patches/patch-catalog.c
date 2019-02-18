$NetBSD: patch-catalog.c,v 1.1.2.2 2019/02/18 14:05:52 bsiegert Exp $

Parametrize XML and SGML catalog directories.

--- catalog.c.orig	2014-10-03 11:28:05.000000000 +0000
+++ catalog.c
@@ -70,10 +70,10 @@
 #define XML_URN_PUBID "urn:publicid:"
 #define XML_CATAL_BREAK ((xmlChar *) -1)
 #ifndef XML_XML_DEFAULT_CATALOG
-#define XML_XML_DEFAULT_CATALOG "file:///etc/xml/catalog"
+#define XML_XML_DEFAULT_CATALOG "file://@@XML_DEFAULT_CATALOG@@"
 #endif
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "file:///etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "file://@@SGML_DEFAULT_CATALOG@@"
 #endif
 
 #if defined(_WIN32) && defined(_MSC_VER)

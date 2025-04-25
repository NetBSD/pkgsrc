$NetBSD: patch-libs_kxml_xml.c,v 1.1 2025/04/25 07:37:15 wiz Exp $

libxml2 2.14 compatibility.

--- libs/kxml/xml.c.orig	2025-04-25 07:35:01.143677606 +0000
+++ libs/kxml/xml.c
@@ -171,7 +171,7 @@ rc_t KXMLMgrSchemaValidate ( const KXMLM
 }
 #endif
 
-static void s_xmlGenericErrorDefaultFunc(void *ctx ATTRIBUTE_UNUSED,
+static void s_xmlGenericErrorDefaultFunc(void *ctx,
     const char *msg,
     ...)
 {

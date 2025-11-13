$NetBSD: patch-bindings_xml_expat__xmlparser.c,v 1.1 2025/11/13 22:26:26 wiz Exp $

Fix calloc argument order.

--- bindings/xml/expat_xmlparser.c.orig	2023-12-27 15:52:07.000000000 +0000
+++ bindings/xml/expat_xmlparser.c
@@ -484,7 +484,7 @@ dom_xml_parser_create(const char *enc, c
 
 	UNUSED(int_enc);
 
-	parser = calloc(sizeof(*parser), 1);
+	parser = calloc(1, sizeof(*parser));
 	if (parser == NULL) {
 		msg(DOM_MSG_CRITICAL, mctx, "No memory for parser");
 		return NULL;

$NetBSD: patch-ext_xml_compat.c,v 1.1 2025/06/14 13:57:10 taca Exp $

Fix parse error some XML file so that lang/pear work again.
<https://github.com/php/php-src/issues/14834>

--- ext/xml/compat.c.orig	2025-06-14 13:53:58.516004875 +0000
+++ ext/xml/compat.c
@@ -376,7 +376,7 @@ _get_entity(void *user, const xmlChar *n
 		if (ret == NULL)
 			ret = xmlGetDocEntity(parser->parser->myDoc, name);
 
-		if (ret == NULL || (parser->parser->instate != XML_PARSER_ENTITY_VALUE && parser->parser->instate != XML_PARSER_ATTRIBUTE_VALUE)) {
+		if (ret == NULL || parser->parser->instate == XML_PARSER_CONTENT) {
 			if (ret == NULL || ret->etype == XML_INTERNAL_GENERAL_ENTITY || ret->etype == XML_INTERNAL_PARAMETER_ENTITY || ret->etype == XML_INTERNAL_PREDEFINED_ENTITY) {
 				/* Predefined entities will expand unless no cdata handler is present */
 				if (parser->h_default && ! (ret && ret->etype == XML_INTERNAL_PREDEFINED_ENTITY && parser->h_cdata)) {

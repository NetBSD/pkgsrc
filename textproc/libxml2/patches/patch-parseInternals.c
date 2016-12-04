$NetBSD: patch-parseInternals.c,v 1.1.2.2 2016/12/04 15:40:22 bsiegert Exp $

CVE-2016-9318 https://bugzilla.gnome.org/show_bug.cgi?id=772726

--- parserInternals.c.orig	2016-11-30 14:35:55.000000000 +0000
+++ parserInternals.c
@@ -1438,6 +1438,11 @@ xmlNewEntityInputStream(xmlParserCtxtPtr
                 break;
             case XML_EXTERNAL_GENERAL_PARSED_ENTITY:
             case XML_EXTERNAL_PARAMETER_ENTITY:
+		if (((ctxt->options & XML_PARSE_NOENT) == 0) &&
+		    ((ctxt->options & XML_PARSE_DTDVALID) == 0)) {
+		    xmlErrInternal(ctxt, "xmlNewEntityInputStream will not read content for external entity\n",
+				    NULL);
+		}
 		return(xmlLoadExternalEntity((char *) entity->URI,
 		       (char *) entity->ExternalID, ctxt));
             case XML_INTERNAL_GENERAL_ENTITY:

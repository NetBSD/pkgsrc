$NetBSD: patch-parser.c,v 1.1 2014/05/10 22:45:42 spz Exp $

Do not fetch external parameter entities (CVE-2014-0191)
https://git.gnome.org/browse/libxml2/commit/?id=9cd1c3cfbd32655d60572c0a413e017260c854df

--- parser.c.orig	2013-04-16 13:39:18.000000000 +0000
+++ parser.c
@@ -2595,6 +2595,20 @@ xmlParserHandlePEReference(xmlParserCtxt
 		    xmlCharEncoding enc;
 
 		    /*
+		     * Note: external parsed entities will not be loaded, it is
+		     * not required for a non-validating parser, unless the
+		     * option of validating, or substituting entities were
+		     * given. Doing so is far more secure as the parser will
+		     * only process data coming from the document entity by
+		     * default.
+		     */
+		    if ((entity->etype == XML_EXTERNAL_PARAMETER_ENTITY) &&
+		        ((ctxt->options & XML_PARSE_NOENT) == 0) &&
+		        ((ctxt->options & XML_PARSE_DTDVALID) == 0) &&
+			(ctxt->validate == 0))
+			return;
+
+		    /*
 		     * handle the extra spaces added before and after
 		     * c.f. http://www.w3.org/TR/REC-xml#as-PE
 		     * this is done independently.

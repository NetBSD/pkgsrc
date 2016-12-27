$NetBSD: patch-xpath.c,v 1.1 2016/12/27 02:34:34 sevan Exp $

CVE-2016-5131
https://git.gnome.org/browse/libxml2/commit/?id=9ab01a277d71f54d3143c2cf333c5c2e9aaedd9e

--- xpath.c.orig	2016-12-27 02:21:53.000000000 +0000
+++ xpath.c
@@ -10691,13 +10691,18 @@ xmlXPathCompPathExpr(xmlXPathParserConte
 		    lc = 1;
 		    break;
 		} else if ((NXT(len) == '(')) {
-		    /* Note Type or Function */
+		    /* Node Type or Function */
 		    if (xmlXPathIsNodeType(name)) {
 #ifdef DEBUG_STEP
 		        xmlGenericError(xmlGenericErrorContext,
 				"PathExpr: Type search\n");
 #endif
 			lc = 1;
+#ifdef LIBXML_XPTR_ENABLED
+                    } else if (ctxt->xptr &&
+                               xmlStrEqual(name, BAD_CAST "range-to")) {
+                        lc = 1;
+#endif
 		    } else {
 #ifdef DEBUG_STEP
 		        xmlGenericError(xmlGenericErrorContext,

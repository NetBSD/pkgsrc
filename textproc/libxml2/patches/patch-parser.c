$NetBSD: patch-parser.c,v 1.3 2017/06/21 00:23:24 tez Exp $

There were two bugs where parameter-entity references could lead to an
unexpected change of the input buffer in xmlParseNameComplex and
xmlDictLookup being called with an invalid pointer.

Percent sign in DTD Names
=========================

This fixes bug 766956 initially reported by Wei Lei and independently by
Chromium's ClusterFuzz, Hanno Böck, and Marco Grassi. Thanks to everyone
involved.

xmlParseNameComplex with XML_PARSE_OLD10
========================================

This fixes bugs 781205 (CVE-2017-9049) and 781361 (CVE-2017-9050).
Thanks to Marcel Böhme and Thuan Pham for the report.

Additional hardening
====================

A separate check was added in xmlParseNameComplex to validate the
buffer size.

From: https://git.gnome.org/browse/libxml2/commit/?id=e26630548e7d138d2c560844c43820b6767251e3


--- parser.c.orig
+++ parser.c
@@ -2121,7 +2121,6 @@ static void xmlGROW (xmlParserCtxtPtr ctxt) {
 	ctxt->input->line++; ctxt->input->col = 1;			\
     } else ctxt->input->col++;						\
     ctxt->input->cur += l;				\
-    if (*ctxt->input->cur == '%') xmlParserHandlePEReference(ctxt);	\
   } while (0)
 
 #define CUR_CHAR(l) xmlCurrentChar(ctxt, &l)
@@ -3412,13 +3411,6 @@ xmlParseNameComplex(xmlParserCtxtPtr ctxt) {
 	    len += l;
 	    NEXTL(l);
 	    c = CUR_CHAR(l);
-	    if (c == 0) {
-		count = 0;
-		GROW;
-                if (ctxt->instate == XML_PARSER_EOF)
-                    return(NULL);
-		c = CUR_CHAR(l);
-	    }
 	}
     }
     if ((len > XML_MAX_NAME_LENGTH) &&
@@ -3426,6 +3418,16 @@ xmlParseNameComplex(xmlParserCtxtPtr ctxt) {
         xmlFatalErr(ctxt, XML_ERR_NAME_TOO_LONG, "Name");
         return(NULL);
     }
+    if (ctxt->input->cur - ctxt->input->base < len) {
+        /*
+         * There were a couple of bugs where PERefs lead to to a change
+         * of the buffer. Check the buffer size to avoid passing an invalid
+         * pointer to xmlDictLookup.
+         */
+        xmlFatalErr(ctxt, XML_ERR_INTERNAL_ERROR,
+                    "unexpected change of input buffer");
+        return (NULL);
+    }
     if ((*ctxt->input->cur == '\n') && (ctxt->input->cur[-1] == '\r'))
         return(xmlDictLookup(ctxt->dict, ctxt->input->cur - (len + 1), len));
     return(xmlDictLookup(ctxt->dict, ctxt->input->cur - len, len));

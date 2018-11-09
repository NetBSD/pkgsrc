$NetBSD: patch-parser.c,v 1.5 2018/11/09 15:31:46 leot Exp $

Fixes CVE-2017-8872.

https://bugzilla.gnome.org/show_bug.cgi?id=775200
https://gitlab.gnome.org/GNOME/libxml2/issues/26
https://gitlab.gnome.org/GNOME/libxml2/commit/123234f2cfcd9e9b9f83047eee1dc17b4c3f4407

--- parser.c.orig	2018-01-25 06:44:40.000000000 +0000
+++ parser.c
@@ -12462,7 +12462,12 @@ xmlHaltParser(xmlParserCtxtPtr ctxt) {
 	    ctxt->input->free((xmlChar *) ctxt->input->base);
 	    ctxt->input->free = NULL;
 	}
+        if (ctxt->input->buf != NULL) {
+            xmlFreeParserInputBuffer(ctxt->input->buf);
+            ctxt->input->buf = NULL;
+        }
 	ctxt->input->cur = BAD_CAST"";
+        ctxt->input->length = 0;
 	ctxt->input->base = ctxt->input->cur;
         ctxt->input->end = ctxt->input->cur;
     }

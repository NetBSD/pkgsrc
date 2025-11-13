$NetBSD: patch-src_html_html__document.c,v 1.1 2025/11/13 22:26:26 wiz Exp $

Fix calloc argument order.

--- src/html/html_document.c.orig	2025-11-13 22:25:26.739012429 +0000
+++ src/html/html_document.c
@@ -134,13 +134,12 @@ dom_exception _dom_html_document_initial
 	doc->cookie = NULL;
 	doc->body = NULL;
 
-	doc->memoised = calloc(sizeof(dom_string *), hds_COUNT);
+	doc->memoised = calloc(hds_COUNT, sizeof(dom_string *));
 	if (doc->memoised == NULL) {
 		error = DOM_NO_MEM_ERR;
 		goto out;
 	}
-	doc->elements = calloc(sizeof(dom_string *),
-			DOM_HTML_ELEMENT_TYPE__COUNT);
+	doc->elements = calloc(DOM_HTML_ELEMENT_TYPE__COUNT, sizeof(dom_string *));
 	if (doc->elements == NULL) {
 		error = DOM_NO_MEM_ERR;
 		goto out;

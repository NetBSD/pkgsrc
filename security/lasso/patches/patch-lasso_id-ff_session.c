$NetBSD: patch-lasso_id-ff_session.c,v 1.2 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/lasso/id-ff/session.c b/lasso/id-ff/session.c
index a64f379..f770348 100644
--- lasso/id-ff/session.c
+++ lasso/id-ff/session.c
@@ -437,27 +437,12 @@ add_assertion_childnode(gchar *key, LassoLibAssertion *value, DumpContext *conte
 
 xmlChar *
 xmlNode_to_base64(xmlNode *node) {
-	xmlOutputBufferPtr buf = NULL;
-	xmlCharEncodingHandlerPtr handler = NULL;
-	xmlChar *buffer = NULL;
+	gchar *buffer = NULL;
 	xmlChar *ret = NULL;
 
-	handler = xmlFindCharEncodingHandler("utf-8");
-	if (! handler)
-		goto cleanup;
-	buf = xmlAllocOutputBuffer(handler);
-	if (! buf)
-		goto cleanup;
-	xmlNodeDumpOutput(buf, NULL, node, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
-
-	ret = xmlSecBase64Encode(buffer, strlen((char*)buffer), 0);
-
-cleanup:
-	if (buf)
-		xmlOutputBufferClose(buf);
-
+	buffer = lasso_xmlnode_to_string(node, 0, 0);
+	ret = xmlSecBase64Encode(BAD_CAST buffer, strlen((char*)buffer), 0);
+	lasso_release_string(buffer);
 	return ret;
 }
 

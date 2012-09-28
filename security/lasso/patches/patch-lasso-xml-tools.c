$NetBSD: patch-lasso-xml-tools.c,v 1.2 2012/09/28 11:59:18 obache Exp $

* XXX
* for libxml>=2.9.0

--- lasso/xml/tools.c.orig	2011-01-05 13:57:32.000000000 +0000
+++ lasso/xml/tools.c
@@ -27,6 +27,7 @@
 /* permit importation of timegm for glibc2, wait for people to complain it does not work on their
  * system. */
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #include "private.h"
 #include <string.h>
 #include <time.h>
@@ -1063,7 +1064,7 @@ lasso_node_build_deflated_query(LassoNod
 	buf = xmlAllocOutputBuffer(handler);
 	xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 0, "utf-8");
 	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
+	buffer = xmlBufferContent(buf->conv ? buf->conv : buf->buffer);
 
 	xmlFreeNode(xmlnode);
 	xmlnode = NULL;
@@ -1196,6 +1197,11 @@ lasso_concat_url_query(const char *url, 
  *
  * Return value: TRUE if no error occurred during evaluation, FALSE otherwise.
  */
+static void
+structuredErrorFunc (void *userData, xmlErrorPtr error) {
+	*(int *)userData = error->code;
+}
+
 gboolean
 lasso_eval_xpath_expression(xmlXPathContextPtr xpath_ctx, const char *expression,
 		xmlXPathObjectPtr *xpath_object_ptr, int *xpath_error_code)
@@ -1205,10 +1211,6 @@ lasso_eval_xpath_expression(xmlXPathCont
 	xmlStructuredErrorFunc oldStructuredErrorFunc;
 	gboolean rc = TRUE;
 
-	void structuredErrorFunc (G_GNUC_UNUSED void *userData, xmlErrorPtr error) {
-		errorCode = error->code;
-	}
-
 	g_return_val_if_fail(xpath_ctx != NULL && expression != NULL, FALSE);
 
 	if (xpath_error_code) { /* reset */
@@ -1216,6 +1218,7 @@ lasso_eval_xpath_expression(xmlXPathCont
 	}
 	oldStructuredErrorFunc = xpath_ctx->error;
 	xpath_ctx->error = structuredErrorFunc;
+	xpath_ctx->userData = &errorCode;
 	xpath_object = xmlXPathEvalExpression((xmlChar*)expression, xpath_ctx);
 	xpath_ctx->error = oldStructuredErrorFunc;
 
@@ -2156,7 +2159,7 @@ lasso_xmlnode_to_string(xmlNode *node, g
 	buf = xmlAllocOutputBuffer(handler);
 	xmlNodeDumpOutput(buf, NULL, node, level, format ? 1 : 0, "utf-8");
 	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
+	buffer = xmlBufferContent(buf->conv ? buf->conv : buf->buffer);
 	/* do not mix XML and GLib strings, so we must copy */
 	str = g_strdup((char*)buffer);
 	xmlOutputBufferClose(buf);

$NetBSD: patch-lasso-xml-tools.c,v 1.5 2012/12/15 15:29:28 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

Don't use nested functions.

diff --git a/lasso/xml/tools.c b/lasso/xml/tools.c
index c4b3c8a..cda8775 100644
--- lasso/xml/tools.c.orig	2011-11-29 09:19:49.000000000 +0000
+++ lasso/xml/tools.c
@@ -27,6 +27,7 @@
 /* permit importation of timegm for glibc2, wait for people to complain it does not work on their
  * system. */
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #include "private.h"
 #include <string.h>
 #include <time.h>
@@ -36,6 +37,7 @@
 #include <libxml/uri.h>
 #include <libxml/parser.h>
 #include <libxml/parserInternals.h>
+#include <libxml/xmlIO.h>
 
 #include <openssl/pem.h>
 #include <openssl/sha.h>
@@ -1043,38 +1045,30 @@ lasso_sign_node(xmlNode *xmlnode, const 
 	return 0;
 }
 
-gchar*
-lasso_node_build_deflated_query(LassoNode *node)
+static gchar*
+lasso_xmlnode_build_deflated_query(xmlNode *xmlnode)
 {
-	/* actually deflated and b64'ed and url-escaped */
-	xmlNode *xmlnode;
-	xmlOutputBufferPtr buf;
-	xmlCharEncodingHandlerPtr handler = NULL;
-	xmlChar *buffer;
+	xmlOutputBuffer *output_buffer;
+	xmlBuffer *buffer;
 	xmlChar *ret, *b64_ret;
 	char *rret;
 	unsigned long in_len;
 	int rc = 0;
 	z_stream stream;
 
-	xmlnode = lasso_node_get_xmlNode(node, FALSE);
-
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
-
-	xmlFreeNode(xmlnode);
-	xmlnode = NULL;
-
-	in_len = strlen((char*)buffer);
+	buffer = xmlBufferCreate();
+	output_buffer = xmlOutputBufferCreateBuffer(buffer, NULL);
+	xmlNodeDumpOutput(output_buffer, NULL, xmlnode, 0, 0, NULL);
+	xmlOutputBufferClose(output_buffer);
+	xmlBufferAdd(buffer, BAD_CAST "", 1);
+
+	in_len = strlen((char*)xmlBufferContent(buffer));
 	ret = g_malloc(in_len * 2);
 		/* deflating should never increase the required size but we are
 		 * more conservative than that.  Twice the size should be
 		 * enough. */
 
-	stream.next_in = buffer;
+	stream.next_in = (xmlChar*)xmlBufferContent(buffer);
 	stream.avail_in = in_len;
 	stream.next_out = ret;
 	stream.avail_out = in_len * 2;
@@ -1097,6 +1091,7 @@ lasso_node_build_deflated_query(LassoNod
 			rc = deflateEnd(&stream);
 		}
 	}
+	xmlBufferFree(buffer);
 	if (rc != Z_OK) {
 		lasso_release(ret);
 		message(G_LOG_LEVEL_CRITICAL, "Failed to deflate");
@@ -1104,7 +1099,6 @@ lasso_node_build_deflated_query(LassoNod
 	}
 
 	b64_ret = xmlSecBase64Encode(ret, stream.total_out, 0);
-	xmlOutputBufferClose(buf);
 	lasso_release(ret);
 
 	ret = xmlURIEscapeStr(b64_ret, NULL);
@@ -1115,6 +1109,20 @@ lasso_node_build_deflated_query(LassoNod
 	return rret;
 }
 
+gchar*
+lasso_node_build_deflated_query(LassoNode *node)
+{
+	/* actually deflated and b64'ed and url-escaped */
+	xmlNode *xmlnode;
+	gchar *result;
+
+	xmlnode = lasso_node_get_xmlNode(node, FALSE);
+	result = lasso_xmlnode_build_deflated_query(xmlnode);
+	xmlFreeNode(xmlnode);
+	return result;
+}
+
+
 gboolean
 lasso_node_init_from_deflated_query_part(LassoNode *node, char *deflate_string)
 {
@@ -1196,28 +1204,34 @@ lasso_concat_url_query(const char *url, 
  *
  * Return value: TRUE if no error occurred during evaluation, FALSE otherwise.
  */
+static void
+structuredErrorFunc (void *userData, xmlErrorPtr error) {
+	struct wrapped_cb_data *data = userData;
+	*(int *)userData = error->code;
+}
+
 gboolean
 lasso_eval_xpath_expression(xmlXPathContextPtr xpath_ctx, const char *expression,
 		xmlXPathObjectPtr *xpath_object_ptr, int *xpath_error_code)
 {
-	xmlXPathObject *xpath_object = NULL;
-	int errorCode = 0;
 	xmlStructuredErrorFunc oldStructuredErrorFunc;
+	void *oldUserData;
+	int errorCode = 0;
+	xmlXPathObject *xpath_object = NULL;
 	gboolean rc = TRUE;
 
-	void structuredErrorFunc (G_GNUC_UNUSED void *userData, xmlErrorPtr error) {
-		errorCode = error->code;
-	}
-
 	g_return_val_if_fail(xpath_ctx != NULL && expression != NULL, FALSE);
 
 	if (xpath_error_code) { /* reset */
 		*xpath_error_code = 0;
 	}
 	oldStructuredErrorFunc = xpath_ctx->error;
+	oldUserData = xpath_ctx->userData;
 	xpath_ctx->error = structuredErrorFunc;
+	xpath_ctx->userData = &errorCode;
 	xpath_object = xmlXPathEvalExpression((xmlChar*)expression, xpath_ctx);
 	xpath_ctx->error = oldStructuredErrorFunc;
+	xpath_ctx->userData = oldUserData;
 
 	if (xpath_object) {
 		if (xpath_object_ptr) {
@@ -2144,22 +2158,21 @@ cleanup:
 char*
 lasso_xmlnode_to_string(xmlNode *node, gboolean format, int level)
 {
-	xmlOutputBufferPtr buf;
-	xmlCharEncodingHandlerPtr handler = NULL;
-	xmlChar *buffer;
+	xmlOutputBufferPtr output_buffer;
+	xmlBuffer *buffer;
 	char *str;
 
 	if (! node)
 		return NULL;
 
-	handler = xmlFindCharEncodingHandler("utf-8");
-	buf = xmlAllocOutputBuffer(handler);
-	xmlNodeDumpOutput(buf, NULL, node, level, format ? 1 : 0, "utf-8");
-	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
+	buffer = xmlBufferCreate();
+	output_buffer = xmlOutputBufferCreateBuffer(buffer, NULL);
+	xmlNodeDumpOutput(output_buffer, NULL, node, level, format ? 1 : 0, NULL);
+	xmlOutputBufferClose(output_buffer);
+	xmlBufferAdd(buffer, BAD_CAST "", 1);
 	/* do not mix XML and GLib strings, so we must copy */
-	str = g_strdup((char*)buffer);
-	xmlOutputBufferClose(buf);
+	str = g_strdup((char*)xmlBufferContent(buffer));
+	xmlBufferFree(buffer);
 
 	return str;
 }

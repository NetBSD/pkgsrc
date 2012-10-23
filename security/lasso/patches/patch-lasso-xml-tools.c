$NetBSD: patch-lasso-xml-tools.c,v 1.3 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/lasso/xml/tools.c b/lasso/xml/tools.c
index c4b3c8a..cda8775 100644
--- lasso/xml/tools.c
+++ lasso/xml/tools.c
@@ -36,6 +36,7 @@
 #include <libxml/uri.h>
 #include <libxml/parser.h>
 #include <libxml/parserInternals.h>
+#include <libxml/xmlIO.h>
 
 #include <openssl/pem.h>
 #include <openssl/sha.h>
@@ -1043,38 +1044,30 @@ lasso_sign_node(xmlNode *xmlnode, const char *id_attr_name, const char *id_value
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
+	lasso_release_xml_node(xmlnode);
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
@@ -1097,6 +1090,7 @@ lasso_node_build_deflated_query(LassoNode *node)
 			rc = deflateEnd(&stream);
 		}
 	}
+	xmlBufferFree(buffer);
 	if (rc != Z_OK) {
 		lasso_release(ret);
 		message(G_LOG_LEVEL_CRITICAL, "Failed to deflate");
@@ -1104,7 +1098,6 @@ lasso_node_build_deflated_query(LassoNode *node)
 	}
 
 	b64_ret = xmlSecBase64Encode(ret, stream.total_out, 0);
-	xmlOutputBufferClose(buf);
 	lasso_release(ret);
 
 	ret = xmlURIEscapeStr(b64_ret, NULL);
@@ -1115,6 +1108,20 @@ lasso_node_build_deflated_query(LassoNode *node)
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
@@ -2144,22 +2151,21 @@ cleanup:
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
-- 
1.7.4.1


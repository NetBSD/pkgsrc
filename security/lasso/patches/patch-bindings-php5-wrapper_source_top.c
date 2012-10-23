$NetBSD: patch-bindings-php5-wrapper_source_top.c,v 1.1 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/bindings/php5/wrapper_source_top.c b/bindings/php5/wrapper_source_top.c
index 67a279a..0b1db97 100644
--- bindings/php5/wrapper_source_top.c
+++ bindings/php5/wrapper_source_top.c
@@ -119,31 +119,41 @@ free_glist(GList **list, GFunc free_function) {
 }
 /* Conversion functions */
 
+static xmlBuffer*
+xmlnode_to_xmlbuffer(xmlNode *node)
+{
+	xmlOutputBufferPtr output_buffer;
+	xmlBuffer *buffer;
+
+	if (! node)
+		return NULL;
+
+	buffer = xmlBufferCreate();
+	output_buffer = xmlOutputBufferCreateBuffer(buffer, NULL);
+	xmlNodeDumpOutput(output_buffer, NULL, node, 0, 0, NULL);
+	xmlOutputBufferClose(output_buffer);
+	xmlBufferAdd(buffer, BAD_CAST "", 1);
+
+	return buffer;
+}
+
 static char*
 get_string_from_xml_node(xmlNode *xmlnode)
 {
-	xmlOutputBufferPtr buf;
-	char *xmlString;
+	xmlBuffer *buffer;
+	char *result;
 
 	if (xmlnode == NULL) {
 		return NULL;
 	}
-
-	buf = xmlAllocOutputBuffer(NULL);
-	if (buf == NULL) {
-		xmlString = NULL;
+	buffer = xmlnode_to_xmlbuffer(xmlnode);
+	if (buffer == NULL) {
+		result = NULL;
 	} else {
-		xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 1, NULL);
-		xmlOutputBufferFlush(buf);
-		if (buf->conv == NULL) {
-			xmlString = estrdup((char*)buf->buffer->content);
-		} else {
-			xmlString = estrdup((char*)buf->conv->content);
-		}
-		xmlOutputBufferClose(buf);
+		result = estrdup((char*)xmlBufferContent(buffer));
+		xmlBufferFree(buffer);
 	}
-
-	return xmlString;
+	return result;
 }
 
 static xmlNode*

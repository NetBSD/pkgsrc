$NetBSD: patch-bindings-python-wrapper_top.c,v 1.1 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/bindings/python/wrapper_top.c b/bindings/python/wrapper_top.c
index 7879bb1..2c68437 100644
--- bindings/python/wrapper_top.c
+++ bindings/python/wrapper_top.c
@@ -103,28 +103,40 @@ get_dict_from_hashtable_of_strings(GHashTable *value)
 	return proxy;
 }
 
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
 static PyObject*
 get_pystring_from_xml_node(xmlNode *xmlnode)
 {
-	xmlOutputBufferPtr buf;
 	PyObject *pystring = NULL;
+	xmlBuffer *buffer;
 
 	if (xmlnode == NULL) {
 		return NULL;
 	}
+	buffer = xmlnode_to_xmlbuffer(xmlnode);
 
-	buf = xmlAllocOutputBuffer(NULL);
-	if (buf == NULL) {
+	if (buffer == NULL) {
 		pystring = NULL;
 	} else {
-		xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 1, NULL);
-		xmlOutputBufferFlush(buf);
-		if (buf->conv == NULL) {
-			pystring = PyString_FromString((char*)buf->buffer->content);
-		} else {
-			pystring = PyString_FromString((char*)buf->conv->content);
-		}
-		xmlOutputBufferClose(buf);
+		pystring = PyString_FromString((char*)xmlBufferContent(buffer));
+		xmlBufferFree(buffer);
 	}
 
 	return pystring;

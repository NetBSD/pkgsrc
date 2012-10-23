$NetBSD: patch-bindings-java-wrapper_top.c,v 1.1 2012/10/23 18:16:15 manu Exp $

Patch from upstream to support libxml >= 2.9.0. From commit message:

Libxml stopped exposing the internal of the xmlOutputBuffer structure;
it was replace by proper use of the API and of the xmlBuffer structure.

There could be regression for older version of libxml as some functions
appeared in recent version of libxml; but the reference API document
does not give any introduction date for functions so it's hard to be
sure.

diff --git a/bindings/java/wrapper_top.c b/bindings/java/wrapper_top.c
index dfdec34..54bdeef 100644
--- bindings/java/wrapper_top.c
+++ bindings/java/wrapper_top.c
@@ -282,35 +282,39 @@ jstring_to_string(JNIEnv *env, jstring jstr, char **str) {
 
 
 /* xmlNode handling */
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
 static int
 xml_node_to_jstring(JNIEnv *env, xmlNode *xmlnode, jstring *jstr) {
-    xmlOutputBufferPtr buf = NULL;
+    xmlBuffer *buffer;
 
     g_error_if_fail(env);
     if (! xmlnode) {
         *jstr = NULL;
         return 1;
     }
-
-    buf = xmlAllocOutputBuffer(NULL);
-    if (buf) {
-        int ret = 1;
-        xmlNodeDumpOutput(buf, NULL, xmlnode, 0, 1, NULL);
-        xmlOutputBufferFlush(buf);
-        xmlChar *str = NULL;
-        if (buf->conv == NULL) {
-            str = buf->buffer->content;
-        } else {
-            str = buf->conv->content;
-        }
-        ret = string_to_jstring(env, (char*)str, jstr);
-        xmlOutputBufferClose(buf);
-        return ret;
-    } else {
+    buffer = xmlnode_to_xmlbuffer(xmlnode);
+    if (! buffer) {
         exception(env, "could not alloc an xml output buffer");
         return 0;
     }
-    return 1;
+    return string_to_jstring(env, (char*)xmlBufferContent(buffer), jstr);
 }
 
 /** Convert a java string to an xml node. Return 0 if it failed with an exception

$NetBSD: patch-lasso_id-ff_session.c,v 1.1 2012/09/28 11:59:18 obache Exp $

* for libxml2>=2.9.0

--- lasso/id-ff/session.c.orig	2011-01-05 13:57:32.000000000 +0000
+++ lasso/id-ff/session.c
@@ -450,7 +450,7 @@ xmlNode_to_base64(xmlNode *node) {
 		goto cleanup;
 	xmlNodeDumpOutput(buf, NULL, node, 0, 0, "utf-8");
 	xmlOutputBufferFlush(buf);
-	buffer = buf->conv ? buf->conv->content : buf->buffer->content;
+	buffer = xmlBufferContent(buf->conv ? buf->conv : buf->buffer);
 
 	ret = xmlSecBase64Encode(buffer, strlen((char*)buffer), 0);
 

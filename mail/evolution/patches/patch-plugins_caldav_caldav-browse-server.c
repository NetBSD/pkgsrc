$NetBSD: patch-plugins_caldav_caldav-browse-server.c,v 1.1 2012/09/21 11:49:20 obache Exp $

* support both old and new-buf libxml2 APIs

--- plugins/caldav/caldav-browse-server.c.orig	2011-03-29 18:38:48.000000000 +0000
+++ plugins/caldav/caldav-browse-server.c
@@ -979,7 +979,13 @@ send_xml_message (xmlDocPtr doc, gboolea
 
 	soup_message_headers_append (message->request_headers, "User-Agent", "Evolution/" VERSION);
 	soup_message_headers_append (message->request_headers, "Depth", depth_1 ? "1" : "0");
-	soup_message_set_request (message, "application/xml", SOUP_MEMORY_COPY, (const gchar *) buf->buffer->content, buf->buffer->use);
+	soup_message_set_request (message, "application/xml", SOUP_MEMORY_COPY,
+#ifdef LIBXML2_NEW_BUFFER
+			(const gchar *) xmlOutputBufferGetContent(buf),
+			xmlOutputBufferGetSize(buf));
+#else
+			(const gchar *) buf->buffer->content, buf->buffer->use);
+#endif
 
 	/* Clean up the memory */
 	xmlOutputBufferClose (buf);

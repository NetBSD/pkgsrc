$NetBSD: patch-calendar_backends_caldav_e-cal-backend-caldav.c,v 1.1 2012/09/20 11:53:19 obache Exp $

* Support both old and new-buf libxml2 APIs
  http://git.gnome.org/browse/evolution-data-server/commit/calendar/backends/caldav/e-cal-backend-caldav.c?id=679b10d75730e81fa268e11cfda289a27fd3e306

--- calendar/backends/caldav/e-cal-backend-caldav.c.orig	2011-04-21 19:35:36.000000000 +0000
+++ calendar/backends/caldav/e-cal-backend-caldav.c
@@ -1024,6 +1024,19 @@ caldav_server_open_calendar (ECalBackend
 	return FALSE;
 }
 
+static gconstpointer
+compat_libxml_output_buffer_get_content (xmlOutputBufferPtr buf,
+                                         gsize *out_len)
+{
+#ifdef LIBXML2_NEW_BUFFER
+	*out_len = xmlOutputBufferGetSize (buf);
+	return xmlOutputBufferGetContent (buf);
+#else
+	*out_len = buf->buffer->use;
+	return buf->buffer->content;
+#endif
+}
+
 /* Returns whether calendar changed on the server. This works only when server
    supports 'getctag' extension. */
 static gboolean
@@ -1035,6 +1048,8 @@ check_calendar_changed_on_server (ECalBa
 	xmlDocPtr		  doc;
 	xmlNodePtr		  root, node;
 	xmlNsPtr		  ns, nsdav;
+	gconstpointer		  buf_content;
+	gsize			  buf_size;
 	gboolean		  result = TRUE;
 
 	g_return_val_if_fail (cbdav != NULL, TRUE);
@@ -1069,11 +1084,11 @@ check_calendar_changed_on_server (ECalBa
 	soup_message_headers_append (message->request_headers,
 				     "Depth", "0");
 
+	buf_content = compat_libxml_output_buffer_get_content (buf, &buf_size);
 	soup_message_set_request (message,
 				  "application/xml",
 				  SOUP_MEMORY_COPY,
-				  (gchar *) buf->buffer->content,
-				  buf->buffer->use);
+				  buf_content, buf_size);
 
 	/* Send the request now */
 	send_and_handle_redirection (priv->session, message, NULL);
@@ -1131,6 +1146,8 @@ caldav_server_list_objects (ECalBackendC
 	xmlDocPtr            doc;
 	xmlNsPtr             nsdav;
 	xmlNsPtr             nscd;
+	gconstpointer        buf_content;
+	gsize                buf_size;
 	gboolean             result;
 
 	priv = E_CAL_BACKEND_CALDAV_GET_PRIVATE (cbdav);
@@ -1211,11 +1228,11 @@ caldav_server_list_objects (ECalBackendC
 	soup_message_headers_append (message->request_headers,
 				     "Depth", "1");
 
+	buf_content = compat_libxml_output_buffer_get_content (buf, &buf_size);
 	soup_message_set_request (message,
 				  "application/xml",
 				  SOUP_MEMORY_COPY,
-				  (gchar *) buf->buffer->content,
-				  buf->buffer->use);
+				  buf_content, buf_size);
 
 	/* Send the request now */
 	send_and_handle_redirection (priv->session, message, NULL);
@@ -1499,6 +1516,8 @@ caldav_receive_schedule_outbox_url (ECal
 	xmlDocPtr doc;
 	xmlNodePtr root, node;
 	xmlNsPtr nsdav;
+	gconstpointer buf_content;
+	gsize buf_size;
 	gchar *owner = NULL;
 
 	g_return_val_if_fail (cbdav != NULL, FALSE);
@@ -1527,11 +1546,11 @@ caldav_receive_schedule_outbox_url (ECal
 	soup_message_headers_append (message->request_headers, "User-Agent", "Evolution/" VERSION);
 	soup_message_headers_append (message->request_headers, "Depth", "0");
 
+	buf_content = compat_libxml_output_buffer_get_content (buf, &buf_size);
 	soup_message_set_request (message,
 				  "application/xml",
 				  SOUP_MEMORY_COPY,
-				  (gchar *) buf->buffer->content,
-				  buf->buffer->use);
+				  buf_content, buf_size);
 
 	/* Send the request now */
 	send_and_handle_redirection (priv->session, message, NULL);
@@ -1577,11 +1596,11 @@ caldav_receive_schedule_outbox_url (ECal
 		soup_message_headers_append (message->request_headers, "User-Agent", "Evolution/" VERSION);
 		soup_message_headers_append (message->request_headers, "Depth", "0");
 
+		buf_content = compat_libxml_output_buffer_get_content (buf, &buf_size);
 		soup_message_set_request (message,
-				  "application/xml",
-				  SOUP_MEMORY_COPY,
-				  (gchar *) buf->buffer->content,
-				  buf->buffer->use);
+					  "application/xml",
+					  SOUP_MEMORY_COPY,
+					  buf_content, buf_size);
 
 		/* Send the request now */
 		send_and_handle_redirection (priv->session, message, NULL);

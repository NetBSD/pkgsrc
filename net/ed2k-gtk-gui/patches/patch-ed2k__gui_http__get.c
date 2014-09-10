$NetBSD: patch-ed2k__gui_http__get.c,v 1.1 2014/09/10 12:22:44 joerg Exp $

--- ed2k_gui/http_get.c.orig	2014-09-09 18:26:42.000000000 +0000
+++ ed2k_gui/http_get.c
@@ -695,7 +695,7 @@ http_get_connection_callback (GConn *con
 
 			data->buf = g_realloc (data->buf, ( data->bufsize + event->length + 1 ) );
 			g_return_if_fail ( data->buf != NULL );
-			g_memmove (data->buf + data->bufsize, event->buffer, event->length);
+			memmove (data->buf + data->bufsize, event->buffer, event->length);
 			data->buf[data->bufsize + event->length]=0x00;		// remember: we allocated +1 for terminating 0
 			data->bufsize += event->length;
 //			g_print ("read %u bytes (total = %8u)\n", length, data->bufsize);

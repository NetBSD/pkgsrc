$NetBSD: patch-libsoup_soup-logger.c,v 1.2 2013/07/14 10:14:26 richard Exp $

fix problems concerning -Werror=format-zero-length and -Werror=format

--- libsoup/soup-logger.c.orig	2013-03-10 16:57:01.000000000 +0000
+++ libsoup/soup-logger.c
@@ -365,7 +365,7 @@ soup_logger_detach (SoupLogger  *logger,
 	soup_session_remove_feature (session, SOUP_SESSION_FEATURE (logger));
 }
 
-static void
+static G_GNUC_PRINTF (4, 5) void
 soup_logger_print (SoupLogger *logger, SoupLoggerLogLevel level,
 		   char direction, const char *format, ...)
 {
@@ -425,7 +425,7 @@ soup_logger_print_basic_auth (SoupLogger
 			*p = '*';
 	}
 	soup_logger_print (logger, SOUP_LOGGER_LOG_HEADERS, '>',
-			   "Authorization: Basic [%.*s]", len, decoded);
+			   "Authorization: Basic [%.*s]", (int)len, decoded);
 	g_free (decoded);
 }
 
@@ -582,7 +582,7 @@ got_informational (SoupMessage *msg, gpo
 	g_mutex_lock (&priv->lock);
 
 	print_response (logger, msg);
-	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', "");
+	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', " ");
 
 	if (msg->status_code == SOUP_STATUS_CONTINUE && msg->request_body->data) {
 		SoupLoggerLogLevel log_level;
@@ -601,7 +601,7 @@ got_informational (SoupMessage *msg, gpo
 					   "%s", msg->request_body->data);
 		}
 
-		soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', "");
+		soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', " ");
 	}
 
 	g_mutex_unlock (&priv->lock);
@@ -616,7 +616,7 @@ got_body (SoupMessage *msg, gpointer use
 	g_mutex_lock (&priv->lock);
 
 	print_response (logger, msg);
-	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', "");
+	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', " ");
 
 	g_mutex_unlock (&priv->lock);
 }
@@ -665,7 +665,7 @@ soup_logger_request_started (SoupSession
 		soup_logger_set_id (logger, socket);
 
 	print_request (logger, msg, session, socket, restarted);
-	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', "");
+	soup_logger_print (logger, SOUP_LOGGER_LOG_MINIMAL, ' ', " ");
 }
 
 static void

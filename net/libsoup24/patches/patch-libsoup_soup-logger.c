$NetBSD: patch-libsoup_soup-logger.c,v 1.3 2013/07/14 11:26:14 richard Exp $

fix problems concerning -Werror=format

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

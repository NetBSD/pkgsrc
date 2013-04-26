$NetBSD: patch-libsoup_soup-logger.c,v 1.1 2013/04/26 19:54:14 joerg Exp $

--- libsoup/soup-logger.c.orig	2013-04-26 18:44:07.000000000 +0000
+++ libsoup/soup-logger.c
@@ -365,7 +365,7 @@ soup_logger_detach (SoupLogger  *logger,
 	soup_session_remove_feature (session, SOUP_SESSION_FEATURE (logger));
 }
 
-static void
+static G_GNUC_PRINTF (4, 5) void
 soup_logger_print (SoupLogger *logger, SoupLoggerLogLevel level,
 		   char direction, const char *format, ...)
 {

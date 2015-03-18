$NetBSD: patch-lastfss.c,v 1.1 2015/03/18 15:04:17 joerg Exp $

--- lastfss.c.orig	2015-03-17 22:25:25.000000000 +0000
+++ lastfss.c
@@ -54,8 +54,8 @@ char atexit_msg[MAXPATHLEN] = { 0 };
 void
 atexit_func(void)
 {
-	if (*atexit_msg != '\0');
-		syslog(LOG_INFO, atexit_msg);
+	if (*atexit_msg != '\0')
+		syslog(LOG_INFO, "%s", atexit_msg);
 	return;
 }
 

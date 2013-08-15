$NetBSD: patch-src_pidgin-libnotify.c,v 1.1 2013/08/15 08:35:13 obache Exp $

* for libnotify-0.7 API change

--- src/pidgin-libnotify.c.orig	2008-12-14 17:45:51.000000000 +0000
+++ src/pidgin-libnotify.c
@@ -286,7 +286,7 @@ notify (const gchar *title,
 		g_free (tr_body);
 		return;
 	}
-	notification = notify_notification_new (title, tr_body, NULL, NULL);
+	notification = notify_notification_new (title, tr_body, NULL);
 	purple_debug_info (PLUGIN_ID, "notify(), new: "
 					 "title: '%s', body: '%s', buddy: '%s'\n",
 					 title, tr_body, best_name (buddy));

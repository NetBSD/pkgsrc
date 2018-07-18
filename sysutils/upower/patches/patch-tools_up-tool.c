$NetBSD: patch-tools_up-tool.c,v 1.1 2018/07/18 19:18:07 bsiegert Exp $

From 4e83fabac13250fdc61ef5db817e82c32b7b301b Mon Sep 17 00:00:00 2001
From: Martin Pitt <martin.pitt@ubuntu.com>
Date: Tue, 17 May 2016 15:36:21 +0200
Subject: [PATCH 2/9] up-tool: Exit early when connecting to upower fails

This avoids spewing dozens of assertions like

   libupower-glib-CRITICAL **: up_client_get_devices: assertion 'UP_IS_CLIENT (client)' failed
   libupower-glib-CRITICAL **: up_device_get_object_path: assertion 'UP_IS_DEVICE (device)' failed

and useless default values and then exiting successfully (which might confuse
users or scripts trying to parse the output).

Use the new up_client_new_full() constructor so that we get a proper GError.

Side issue in https://bugs.freedesktop.org/show_bug.cgi?id=95350

--- tools/up-tool.c
+++ tools/up-tool.c
@@ -285,7 +285,12 @@ main (int argc, char **argv)
 	g_option_context_free (context);
 
 	loop = g_main_loop_new (NULL, FALSE);
-	client = up_client_new ();
+	client = up_client_new_full (NULL, &error);
+	if (client == NULL) {
+		g_warning ("Cannot connect to upowerd: %s", error->message);
+		g_error_free (error);
+		return EXIT_FAILURE;
+	}
 
 	if (opt_version) {
 		gchar *daemon_version;

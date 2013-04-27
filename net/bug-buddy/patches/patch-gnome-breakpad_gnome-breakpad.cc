$NetBSD: patch-gnome-breakpad_gnome-breakpad.cc,v 1.1 2013/04/27 23:06:56 joerg Exp $

--- gnome-breakpad/gnome-breakpad.cc.orig	2013-04-27 21:38:52.000000000 +0000
+++ gnome-breakpad/gnome-breakpad.cc
@@ -410,7 +410,7 @@ check_if_gdb ()
 	gchar *gdb;
 	bool has_debug_symbols = false;
 	char *filename;
-	gchar *appname;
+	const gchar *appname;
 	pid_t pid;
 	gboolean res;
 

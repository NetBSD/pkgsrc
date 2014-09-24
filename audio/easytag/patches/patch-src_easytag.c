$NetBSD: patch-src_easytag.c,v 1.1 2014/09/24 11:39:23 jperkin Exp $

Fix printing of getpid().

--- src/easytag.c.orig	2014-04-22 18:40:46.000000000 +0000
+++ src/easytag.c
@@ -182,7 +182,7 @@ common_init (GApplication *application)
     GtkWidget *HBox, *VBox;
 
     /* Starting messages */
-    Log_Print(LOG_OK,_("Starting EasyTAG version %s (PID: %d)…"),PACKAGE_VERSION,getpid());
+    Log_Print(LOG_OK,_("Starting EasyTAG version %s (PID: %d)…"),PACKAGE_VERSION,(int)getpid());
 #ifdef ENABLE_MP3
     Log_Print(LOG_OK,_("Using libid3tag version %s"), ID3_VERSION);
 #endif

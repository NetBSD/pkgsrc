$NetBSD: patch-src_widgets_desktop-widget.h,v 1.1 2012/11/16 00:54:05 joerg Exp $

--- src/widgets/desktop-widget.h.orig	2012-11-15 16:18:43.000000000 +0000
+++ src/widgets/desktop-widget.h
@@ -239,7 +239,7 @@ struct SPDesktopWidget {
 private:
     GtkWidget *tool_toolbox;
     GtkWidget *aux_toolbox;
-    GtkWidget *commands_toolbox,;
+    GtkWidget *commands_toolbox;
     GtkWidget *snap_toolbox;
 
     static void init(SPDesktopWidget *widget);

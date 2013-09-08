$NetBSD: patch-src_scim__thai__imengine__setup.cpp,v 1.1 2013/09/08 12:40:26 obache Exp $

* restore GTK-2.0 compatibility

--- src/scim_thai_imengine_setup.cpp.orig	2012-06-09 07:59:48.000000000 +0000
+++ src/scim_thai_imengine_setup.cpp
@@ -168,7 +168,11 @@ create_setup_window ()
         GSList*      isc_radiobutton_group = NULL;
 
         // Create the top level box.
+#if GTK_CHECK_VERSION(3,0,0)
         window = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
+        window = gtk_vbox_new (FALSE, 0);
+#endif
         gtk_widget_show (window);
 
         // Keyboard Layout section
@@ -182,7 +186,11 @@ create_setup_window ()
         gtk_container_add (GTK_CONTAINER (window), alignment);
         gtk_alignment_set_padding (GTK_ALIGNMENT (alignment), 0, 0, 12, 0);
 
+#if GTK_CHECK_VERSION(3,0,0)
         vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
+        vbox = gtk_vbox_new (FALSE, 0);
+#endif
         gtk_widget_show (vbox);
         gtk_container_add (GTK_CONTAINER (alignment), vbox);
 
@@ -245,7 +253,11 @@ create_setup_window ()
         gtk_container_add (GTK_CONTAINER (window), alignment);
         gtk_alignment_set_padding (GTK_ALIGNMENT (alignment), 0, 0, 12, 0);
 
+#if GTK_CHECK_VERSION(3,0,0)
         vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
+        vbox = gtk_vbox_new (FALSE, 0);
+#endif
         gtk_widget_show (vbox);
         gtk_container_add (GTK_CONTAINER (alignment), vbox);
 

$NetBSD: patch-src_wp_ap_gtk_ap__UnixFrameImpl.cpp,v 1.1 2018/12/28 22:24:53 gutteridge Exp $

Abiword bug 13791, SVN revision 35482: Disable double buffering on GTK3.

--- src/wp/ap/gtk/ap_UnixFrameImpl.cpp.orig	2016-06-25 22:26:31.000000000 +0000
+++ src/wp/ap/gtk/ap_UnixFrameImpl.cpp
@@ -219,11 +219,12 @@ GtkWidget * AP_UnixFrameImpl::_createDoc
 						    GDK_FOCUS_CHANGE_MASK |
 						    GDK_LEAVE_NOTIFY_MASK |
 						    GDK_SCROLL_MASK));
-	gtk_widget_set_double_buffered(GTK_WIDGET(m_dArea), FALSE);
 #if GTK_CHECK_VERSION(3,0,0)
 	g_signal_connect(G_OBJECT(m_dArea), "draw",
 					   G_CALLBACK(XAP_UnixFrameImpl::_fe::draw), NULL);
 #else
+        // We disable double buffering on Gtk3 because it doesn't work.
+	gtk_widget_set_double_buffered(GTK_WIDGET(m_dArea), FALSE);
 	g_signal_connect(G_OBJECT(m_dArea), "expose_event",
 					   G_CALLBACK(XAP_UnixFrameImpl::_fe::expose), NULL);
 #endif

$NetBSD: patch-gui_support.c,v 1.1 2015/12/12 15:31:26 kamil Exp $

Adapt to newer GTK+ API.

Imported from: https://projects.archlinux.org/svntogit/community.git/plain/trunk/gtk-fix.patch?h=packages/gdmap

--- src/gui_support.c.orig	2008-05-23 14:54:28.000000000 +0000
+++ src/gui_support.c
@@ -85,7 +85,11 @@ on_ebox_enter(GtkWidget* box, GdkEventCr
   const char* text;
 
   (void)event;
+#if GTK_CHECK_VERSION(2,20,0)
+  if (gtk_widget_get_sensitive(GTK_WIDGET(label))) {
+#else
   if (GTK_WIDGET_SENSITIVE(label)) {
+#endif
     char* temp;
 
     text = g_object_get_data(G_OBJECT(label), "label");
@@ -129,7 +133,11 @@ static void on_clear_label(GtkWidget* wi
 void ui_event_label_set_sensitive(GtkWidget* ebox, gboolean set) {
   gpointer callback = g_object_get_data(G_OBJECT(ebox), "callback");
   GtkWidget* child = GTK_BIN(ebox)->child;
+#if GTK_CHECK_VERSION(2,20,0)
+  if (gtk_widget_get_sensitive(child) == set) return;
+#else
   if (GTK_WIDGET_SENSITIVE(child) == set) return;
+#endif
 
   if (set && !callback) return;
   gtk_widget_set_sensitive(child, set);
@@ -164,8 +172,11 @@ GtkWidget* ui_create_event_label(const c
                         // GDK_FOCUS_CHANGE_MASK |
                         GDK_ENTER_NOTIFY_MASK |
                         GDK_LEAVE_NOTIFY_MASK);
+#if GTK_CHECK_VERSION(2,22,0)
+  gtk_widget_set_can_focus(ebox, TRUE);
+#else
   GTK_WIDGET_SET_FLAGS(ebox, GTK_CAN_FOCUS);
-
+#endif
   gtk_widget_show(ebox);
 
   temp = g_strdup_printf(EVENT_FMT, text);

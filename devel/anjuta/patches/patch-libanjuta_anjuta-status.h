$NetBSD: patch-libanjuta_anjuta-status.h,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- libanjuta/anjuta-status.h.orig	2013-08-09 00:30:17.000000000 +0000
+++ libanjuta/anjuta-status.h
@@ -53,14 +53,14 @@ GType anjuta_status_get_type (void);
 GtkWidget* anjuta_status_new (void);
 
 /* Status bar text manipulation */
-void anjuta_status_set (AnjutaStatus *status, const gchar * mesg, ...);
-void anjuta_status_push (AnjutaStatus *status, const gchar * mesg, ...);
+void anjuta_status_set (AnjutaStatus *status, const gchar * mesg, ...) G_GNUC_PRINTF(2,3);
+void anjuta_status_push (AnjutaStatus *status, const gchar * mesg, ...) G_GNUC_PRINTF(2,3);
 void anjuta_status_pop (AnjutaStatus *status);
 void anjuta_status_clear_stack (AnjutaStatus *status);
 void anjuta_status_busy_push (AnjutaStatus *status);
 void anjuta_status_busy_pop (AnjutaStatus *status);
 void anjuta_status_set_default (AnjutaStatus *status, const gchar *label,
-								const gchar *value_format, ...);
+								const gchar *value_format, ...) G_GNUC_PRINTF(3,4);;
 void anjuta_status_add_widget (AnjutaStatus *status, GtkWidget *widget);
 void anjuta_status (AnjutaStatus *status, const gchar *mesg, gint timeout);
 void anjuta_status_set_title_window (AnjutaStatus *status, GtkWidget *window);

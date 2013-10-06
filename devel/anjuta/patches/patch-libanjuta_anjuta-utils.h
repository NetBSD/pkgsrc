$NetBSD: patch-libanjuta_anjuta-utils.h,v 1.1 2013/10/06 20:01:27 joerg Exp $

--- libanjuta/anjuta-utils.h.orig	2013-08-09 00:30:17.000000000 +0000
+++ libanjuta/anjuta-utils.h
@@ -49,16 +49,16 @@ GtkWidget*  anjuta_util_dialog_add_butto
  													 gint response_id);
 
 void		anjuta_util_dialog_error				(GtkWindow *parent,
-						                             const gchar * mesg, ...);
+						                             const gchar * mesg, ...) G_GNUC_PRINTF(2,3);
 void		anjuta_util_dialog_warning				(GtkWindow *parent,
-						                             const gchar * mesg, ...);
+						                             const gchar * mesg, ...) G_GNUC_PRINTF(2,3);
 void		anjuta_util_dialog_info					(GtkWindow *parent,
-							                         const gchar * mesg, ...);
+							                         const gchar * mesg, ...) G_GNUC_PRINTF(2,3);
 void		anjuta_util_dialog_error_system			(GtkWindow* parent, gint errnum,
-													const gchar * mesg, ... );
+													const gchar * mesg, ... ) G_GNUC_PRINTF(3,4);
 gboolean	anjuta_util_dialog_boolean_question		(GtkWindow *parent,
 													gboolean default_to_yes,
-													const gchar * mesg, ...);
+													const gchar * mesg, ...) G_GNUC_PRINTF(3,4);
 gboolean	anjuta_util_dialog_input				(GtkWindow *parent,
 					                                 const gchar *label,
 													 const gchar *default_value,

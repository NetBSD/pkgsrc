$NetBSD: patch-src_rig-gui-buttons.c,v 1.1 2022/04/10 08:04:39 nia Exp $

Fix building with latest hamlib.

--- src/rig-gui-buttons.c.orig	2009-06-01 14:21:27.000000000 +0000
+++ src/rig-gui-buttons.c
@@ -286,7 +286,7 @@ rig_gui_buttons_create_att_selector    (
     /* note: MAXDBLSTSIZ is defined in hamlib; it is the max size of the
         ATT and preamp arrays.
     */
-    while ((i < MAXDBLSTSIZ) && rig_data_get_att_data (i)) {
+    while ((i < HAMLIB_MAXDBLSTSIZ) && rig_data_get_att_data (i)) {
 
         text = g_strdup_printf ("-%d dB", rig_data_get_att_data (i));
         gtk_combo_box_append_text (GTK_COMBO_BOX (att), text);
@@ -346,7 +346,7 @@ rig_gui_buttons_create_preamp_selector  
     /* note: MAXDBLSTSIZ is defined in hamlib; it is the max size of the
         ATT and preamp arrays.
     */
-    while ((i < MAXDBLSTSIZ) && rig_data_get_preamp_data (i)) {
+    while ((i < HAMLIB_MAXDBLSTSIZ) && rig_data_get_preamp_data (i)) {
 
         text = g_strdup_printf ("%d dB", rig_data_get_preamp_data (i));
         gtk_combo_box_append_text (GTK_COMBO_BOX (preamp), text);

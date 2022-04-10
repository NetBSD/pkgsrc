$NetBSD: patch-src_rig-gui-info.c,v 1.1 2022/04/10 08:04:39 nia Exp $

Fix building with latest hamlib.

--- src/rig-gui-info.c.orig	2007-11-16 21:58:22.000000000 +0000
+++ src/rig-gui-info.c
@@ -714,7 +714,7 @@ rig_gui_info_create_tunstep_frame  ()
 	/* Create a table with enough rows to show the
 	   max possible number of unique tuning steps.
 	*/
-	table = gtk_table_new (TSLSTSIZ, 2, FALSE);
+	table = gtk_table_new (HAMLIB_TSLSTSIZ, 2, FALSE);
 
 	label = gtk_label_new (NULL);
 	gtk_label_set_markup (GTK_LABEL (label), _("<b>STEP</b>"));
@@ -746,7 +746,7 @@ rig_gui_info_create_tunstep_frame  ()
 	      }
 	*/
 	/* for each available tuning ste */
-	for (i = 0; i < TSLSTSIZ; i++) {
+	for (i = 0; i < HAMLIB_TSLSTSIZ; i++) {
 
 		gboolean firsthit = TRUE;   /* indicates whether found mode is the first one
 					       for the current tuning step. */
@@ -757,7 +757,7 @@ rig_gui_info_create_tunstep_frame  ()
 		*/
 		if (myrig->caps->tuning_steps[i].ts == 0) {
 
-			i = TSLSTSIZ;
+			i = HAMLIB_TSLSTSIZ;
 		}
 		
 		/* otherwise continue */
@@ -853,7 +853,7 @@ rig_gui_info_create_frontend_frame ()
 	text = g_strdup ("");
 
 	/* loop over all available preamp values and concatenate them into a label */
-	for (i = 0; i < MAXDBLSTSIZ; i++) {
+	for (i = 0; i < HAMLIB_MAXDBLSTSIZ; i++) {
 
 		data = rig_data_get_preamp_data (i);
 
@@ -861,7 +861,7 @@ rig_gui_info_create_frontend_frame ()
 		   reached the terminator
 		*/
 		if (data == 0) {
-			i = MAXDBLSTSIZ;
+			i = HAMLIB_MAXDBLSTSIZ;
 		}
 		else {
 			if (i > 0) {
@@ -900,7 +900,7 @@ rig_gui_info_create_frontend_frame ()
 
 	text = g_strdup ("");
 	/* loop over all available attenuator values and concatenate them into a label */
-	for (i = 0; i < MAXDBLSTSIZ; i++) {
+	for (i = 0; i < HAMLIB_MAXDBLSTSIZ; i++) {
 
 		data = rig_data_get_att_data (i);
 
@@ -908,7 +908,7 @@ rig_gui_info_create_frontend_frame ()
 		   reached the terminator
 		*/
 		if (data == 0) {
-			i = MAXDBLSTSIZ;
+			i = HAMLIB_MAXDBLSTSIZ;
 		}
 		else {
 			if (i > 0) {

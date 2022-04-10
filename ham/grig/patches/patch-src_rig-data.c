$NetBSD: patch-src_rig-data.c,v 1.1 2022/04/10 08:04:39 nia Exp $

Fix building with latest hamlib.

--- src/rig-data.c.orig	2011-06-21 20:57:14.000000000 +0000
+++ src/rig-data.c
@@ -64,10 +64,10 @@ grig_cmd_avail_t has_get;  /*!< Flags to
 
 
 /** \brief List of attenuator values (absolute values). */
-static int att[MAXDBLSTSIZ];
+static int att[HAMLIB_MAXDBLSTSIZ];
 
 /** \brief List of preamp values. */
-static int preamp[MAXDBLSTSIZ];
+static int preamp[HAMLIB_MAXDBLSTSIZ];
 
 /** \brief Bit field of available VFO's */
 static int vfo_list;
@@ -116,7 +116,7 @@ rig_data_set_vfos         (int vfos)
 void
 rig_data_set_att_data (int index, int data)
 {
-	if ((index >= 0) && (index < MAXDBLSTSIZ))
+	if ((index >= 0) && (index < HAMLIB_MAXDBLSTSIZ))
 		att[index] = data;
 }
 
@@ -132,7 +132,7 @@ rig_data_set_att_data (int index, int da
 int
 rig_data_get_att_data (int index)
 {
-	if ((index >= 0) && (index < MAXDBLSTSIZ)) {
+	if ((index >= 0) && (index < HAMLIB_MAXDBLSTSIZ)) {
 		return att[index];
 	}
 	else {
@@ -158,7 +158,7 @@ rig_data_get_att_index    (int data)
 		return -1;
 
 	/* scan through the array */
-	while ((i < MAXDBLSTSIZ) && (att[i] != 0)) {
+	while ((i < HAMLIB_MAXDBLSTSIZ) && (att[i] != 0)) {
 		if (att[i] == data) {
 			return i;
 		}
@@ -182,7 +182,7 @@ rig_data_get_att_index    (int data)
 void
 rig_data_set_preamp_data (int index, int data)
 {
-	if ((index >= 0) && (index < MAXDBLSTSIZ))
+	if ((index >= 0) && (index < HAMLIB_MAXDBLSTSIZ))
 		preamp[index] = data;
 }
 
@@ -198,7 +198,7 @@ rig_data_set_preamp_data (int index, int
 int
 rig_data_get_preamp_data (int index)
 {
-	if ((index >= 0) && (index < MAXDBLSTSIZ)) {
+	if ((index >= 0) && (index < HAMLIB_MAXDBLSTSIZ)) {
 		return preamp[index];
 	}
 	else {
@@ -225,7 +225,7 @@ rig_data_get_preamp_index    (int data)
 		return -1;
 
 	/* scan through the array */
-	while ((i < MAXDBLSTSIZ) && (preamp[i] != 0)) {
+	while ((i < HAMLIB_MAXDBLSTSIZ) && (preamp[i] != 0)) {
 		if (preamp[i] == data) {
 			return i;
 		}

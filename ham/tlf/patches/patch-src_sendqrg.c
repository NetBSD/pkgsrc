$NetBSD: patch-src_sendqrg.c,v 1.1 2022/05/05 13:37:18 nia Exp $

Fix building with latest hamlib.

--- src/sendqrg.c.orig	2007-12-18 15:08:05.000000000 +0000
+++ src/sendqrg.c
@@ -116,13 +116,13 @@ int init_tlf_rig (void)
 			else {
 				if (strlen(rigportname) > 1) {
 						rigportname[strlen(rigportname)-1] = '\0'; // remove '\n'
-						strncpy(my_rig->state.rigport.pathname, rigportname, FILPATHLEN);
+						strncpy(my_rig->state.rigport.pathname, rigportname, HAMLIB_FILPATHLEN);
 				}
 				else {
 					if (rig_port == 0)
-						strncpy(my_rig->state.rigport.pathname, "/dev/ttyS0", FILPATHLEN);
+						strncpy(my_rig->state.rigport.pathname, "/dev/ttyS0", HAMLIB_FILPATHLEN);
 					else
-						strncpy(my_rig->state.rigport.pathname, "/dev/ttyS1", FILPATHLEN);
+						strncpy(my_rig->state.rigport.pathname, "/dev/ttyS1", HAMLIB_FILPATHLEN);
 				}
 
 			}
@@ -132,9 +132,9 @@ int init_tlf_rig (void)
 			if (dcd_type != RIG_DCD_NONE)
 				my_rig->state.dcdport.type.dcd = dcd_type;
 			if (ptt_file)
-				strncpy(my_rig->state.pttport.pathname, ptt_file, FILPATHLEN);
+				strncpy(my_rig->state.pttport.pathname, ptt_file, HAMLIB_FILPATHLEN);
 			if (dcd_file)
-				strncpy(my_rig->state.dcdport.pathname, dcd_file, FILPATHLEN);
+				strncpy(my_rig->state.dcdport.pathname, dcd_file, HAMLIB_FILPATHLEN);
 
 			my_rig->state.rigport.parm.serial.rate = serial_rate ;
 

$NetBSD: patch-src_rig-daemon.c,v 1.2 2022/04/10 08:04:39 nia Exp $

Description: align affected parts for Hamlib4.0
Author: Ervin Hegedus <airween@gmail.com>
From Debian:
https://sources.debian.org/data/main/g/grig/0.8.1-3/debian/patches/04-hamlib-align.patch

--- src/rig-daemon.c.orig	2015-12-19 15:14:27.000000000 +0000
+++ src/rig-daemon.c
@@ -537,7 +537,7 @@ rig_daemon_start       (int          rig
 	}
 
 	/* configure and open rig device */
-	strncpy (myrig->state.rigport.pathname, rigport, FILPATHLEN);
+	strncpy (myrig->state.rigport.pathname, rigport, HAMLIB_FILPATHLEN);
 	g_free (rigport);
 
 	/* set speed if any special whishes */
@@ -1674,12 +1674,12 @@ rig_daemon_exec_cmd         (rig_cmd_t c
 						   is the current frequency within this range?
 						*/
 						if (((mode & myrig->state.rx_range_list[i].modes) == mode) &&
-						    (get->freq1 >= myrig->state.rx_range_list[i].start)    &&
-						    (get->freq1 <= myrig->state.rx_range_list[i].end)) {
+						    (get->freq1 >= myrig->state.rx_range_list[i].startf)    &&
+						    (get->freq1 <= myrig->state.rx_range_list[i].endf)) {
 					
 							found_mode = 1;
-							get->fmin = myrig->state.rx_range_list[i].start;
-							get->fmax = myrig->state.rx_range_list[i].end;
+							get->fmin = myrig->state.rx_range_list[i].startf;
+							get->fmax = myrig->state.rx_range_list[i].endf;
 				
 							grig_debug_local (RIG_DEBUG_VERBOSE,
 									  _("%s: Found frequency range for mode %d"),
@@ -2971,7 +2971,7 @@ rig_daemon_exec_cmd         (rig_cmd_t c
 			val.i = set->voxdel;
 
 			/* try to execute command */
-			retcode = rig_set_level (myrig, RIG_VFO_CURR, RIG_LEVEL_VOX, val);
+			retcode = rig_set_level (myrig, RIG_VFO_CURR, RIG_LEVEL_VOXDELAY, val);
 
 			/* raise anomaly if execution did not succeed */
 			if (retcode != RIG_OK) {
@@ -2996,7 +2996,7 @@ rig_daemon_exec_cmd         (rig_cmd_t c
 			value_t val;
 
 			/* try to execute command */
-			retcode = rig_get_level (myrig, RIG_VFO_CURR, RIG_LEVEL_VOX, &val);
+			retcode = rig_get_level (myrig, RIG_VFO_CURR, RIG_LEVEL_VOXDELAY, &val);
 
 			/* raise anomaly if execution did not succeed */
 			if (retcode != RIG_OK) {

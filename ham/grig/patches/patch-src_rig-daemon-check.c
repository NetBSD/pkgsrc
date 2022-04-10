$NetBSD: patch-src_rig-daemon-check.c,v 1.2 2022/04/10 08:04:39 nia Exp $

Description: align affected parts for Hamlib4.0
Author: Ervin Hegedus <airween@gmail.com>
From Debian:
https://sources.debian.org/data/main/g/grig/0.8.1-3/debian/patches/04-hamlib-align.patch

--- src/rig-daemon-check.c.orig	2010-05-11 19:42:34.000000000 +0000
+++ src/rig-daemon-check.c
@@ -398,12 +398,12 @@ rig_daemon_check_mode     (RIG          
 			*/
 			if (!found_mode &&
 			    ((mode & myrig->state.rx_range_list[i].modes) == mode) &&
-			    (get->freq1 >= myrig->state.rx_range_list[i].start)    &&
-			    (get->freq1 <= myrig->state.rx_range_list[i].end)) {
+			    (get->freq1 >= myrig->state.rx_range_list[i].startf)    &&
+			    (get->freq1 <= myrig->state.rx_range_list[i].endf)) {
 					
 				found_mode = 1;
-				get->fmin = myrig->state.rx_range_list[i].start;
-				get->fmax = myrig->state.rx_range_list[i].end;
+				get->fmin = myrig->state.rx_range_list[i].startf;
+				get->fmax = myrig->state.rx_range_list[i].endf;
 				
 				grig_debug_local (RIG_DEBUG_VERBOSE,
 						  _("%s: Found frequency range for mode %d"),
@@ -884,7 +884,7 @@ rig_daemon_check_level     (RIG         
 	if (has_get->att || has_set->att) {
 		int i = 0;
 
-		while ((i < MAXDBLSTSIZ) && (myrig->state.attenuator[i] != 0)) {
+		while ((i < HAMLIB_MAXDBLSTSIZ) && (myrig->state.attenuator[i] != 0)) {
 			rig_data_set_att_data (i, myrig->state.attenuator[i]);
 			i++;
 		}
@@ -895,7 +895,7 @@ rig_daemon_check_level     (RIG         
 	if (has_get->preamp || has_set->preamp) {
 		int i = 0;
 
-		while ((i < MAXDBLSTSIZ) && (myrig->state.preamp[i] != 0)) {
+		while ((i < HAMLIB_MAXDBLSTSIZ) && (myrig->state.preamp[i] != 0)) {
 			rig_data_set_preamp_data (i, myrig->state.preamp[i]);
 			i++;
 		}

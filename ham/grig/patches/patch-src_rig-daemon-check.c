$NetBSD: patch-src_rig-daemon-check.c,v 1.1 2021/03/09 08:14:01 nia Exp $

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

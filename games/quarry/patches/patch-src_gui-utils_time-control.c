$NetBSD: patch-src_gui-utils_time-control.c,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/gui-utils/time-control.c.orig	2012-11-15 15:19:40.000000000 +0000
+++ src/gui-utils/time-control.c
@@ -95,7 +95,7 @@ time_control_new_from_sgf_node (const Sg
 /* Note that this function only duplicates the settings, not the
  * state of its argument.
  */
-inline TimeControl *
+TimeControl *
 time_control_duplicate (const TimeControl *time_control)
 {
   return time_control_new (time_control->main_time,

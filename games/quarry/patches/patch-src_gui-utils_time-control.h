$NetBSD: patch-src_gui-utils_time-control.h,v 1.1 2012/11/16 00:50:39 joerg Exp $

--- src/gui-utils/time-control.h.orig	2012-11-15 15:19:38.000000000 +0000
+++ src/gui-utils/time-control.h
@@ -55,8 +55,7 @@ struct _TimeControl {
 TimeControl *	time_control_new (int main_time,
 				  int overtime_length, int moves_per_overtime);
 TimeControl *	time_control_new_from_sgf_node (const SgfNode *sgf_node);
-inline TimeControl *
-		time_control_duplicate (const TimeControl *time_control);
+TimeControl *	time_control_duplicate (const TimeControl *time_control);
 void		time_control_init (TimeControl *time_control,
 				   int main_time,
 				   int overtime_length,

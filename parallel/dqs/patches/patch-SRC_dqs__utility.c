$NetBSD: patch-SRC_dqs__utility.c,v 1.1 2013/03/28 21:37:24 joerg Exp $

--- SRC/dqs_utility.c.orig	2013-03-28 16:13:40.000000000 +0000
+++ SRC/dqs_utility.c
@@ -2025,8 +2025,7 @@ void dqs_show_states(how,states)
 }
 
 /************************************************************************/
-int dqs_show_queue_states(state)
-     int state;
+void dqs_show_queue_states(int state)
 {
   
   DENTER_EXT((DQS_EVENT,"dqs_show_queue_states"));

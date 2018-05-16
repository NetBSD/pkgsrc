$NetBSD: patch-plugins_groupwise-features_send-options.c,v 1.1 2018/05/16 16:15:23 jperkin Exp $

Support current libical API.

--- plugins/groupwise-features/send-options.c.orig	2011-03-29 18:38:48.000000000 +0000
+++ plugins/groupwise-features/send-options.c
@@ -276,7 +276,7 @@ e_send_options_copy_general_opts (ESendO
 		gint diff;
 		icaltimetype temp, current;
 
-		temp = icaltime_from_timet (gopts->delay_until, 0);
+		temp = icaltime_from_timet_with_zone (gopts->delay_until, 0, NULL);
 		current = icaltime_today ();
 		diff = temp.day - current.day;
 		ggopts->delay_until = diff;

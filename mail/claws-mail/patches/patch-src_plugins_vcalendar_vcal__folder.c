$NetBSD: patch-src_plugins_vcalendar_vcal__folder.c,v 1.1 2021/07/13 12:35:09 nia Exp $

--- src/plugins/vcalendar/vcal_folder.c.orig	2021-07-10 08:47:14.000000000 +0000
+++ src/plugins/vcalendar/vcal_folder.c
@@ -778,7 +778,7 @@ GSList *vcal_get_events_list(FolderItem 
         			struct icaltimetype dtstart;
         			struct icaltimetype next;
         			icalrecur_iterator* ritr;
-				time_t duration = (time_t) NULL;
+				time_t duration = (time_t) 0;
 				struct icaldurationtype ical_dur;
 				int i = 0;
 

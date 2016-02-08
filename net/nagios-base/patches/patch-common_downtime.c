$NetBSD: patch-common_downtime.c,v 1.1.2.2 2016/02/08 10:12:10 bsiegert Exp $

64bit time_t workaround

--- common/downtime.c.orig	2016-02-07 22:06:39.000000000 +0100
+++ common/downtime.c	2016-02-07 22:07:03.000000000 +0100
@@ -240,7 +240,7 @@
 	/* don't add old or invalid downtimes */
 	if(start_time >= end_time || end_time <= time(NULL)) {
 		log_debug_info(DEBUGL_DOWNTIME, 1, "Invalid start (%lu) or end (%lu) times\n",
-				start_time, end_time);
+				(unsigned long)start_time, (unsigned long)end_time);
 		return ERROR;
 		}
 

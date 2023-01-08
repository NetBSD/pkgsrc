$NetBSD: patch-common_downtime.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- common/downtime.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ common/downtime.c	2023-01-09 07:07:40.075545398 +0900
@@ -240,7 +240,7 @@
 	/* don't add old or invalid downtimes */
 	if(start_time >= end_time || end_time <= time(NULL)) {
 		log_debug_info(DEBUGL_DOWNTIME, 1, "Invalid start (%lu) or end (%lu) times\n",
-				start_time, end_time);
+				(unsigned long)start_time, (unsigned long)end_time);
 		return ERROR;
 		}
 

$NetBSD: patch-base_events.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- base/events.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ base/events.c	2023-01-09 06:59:11.773902761 +0900
@@ -354,7 +354,7 @@
 			if(check_delay > check_window(temp_service)) {
 				log_debug_info(DEBUGL_EVENTS, 0,
 						"  Fixing check time %lu secs too far away\n",
-						check_delay - check_window(temp_service));
+						(unsigned long)(check_delay - check_window(temp_service)));
 				fixed_services++;
 				check_delay = check_window(temp_service);
 				log_debug_info(DEBUGL_EVENTS, 0, "  New check offset: %d\n",
@@ -506,7 +506,7 @@
 		check_delay = mult_factor * scheduling_info.host_inter_check_delay;
 		if(check_delay > check_window(temp_host)) {
 			log_debug_info(DEBUGL_EVENTS, 1, "Fixing check time (off by %lu)\n",
-					check_delay - check_window(temp_host));
+					(unsigned long)(check_delay - check_window(temp_host)));
 			fixed_hosts++;
 			check_delay = ranged_urand(0, check_window(temp_host));
 			}

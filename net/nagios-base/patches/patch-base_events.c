$NetBSD: patch-base_events.c,v 1.4 2023/03/17 11:51:34 jperkin Exp $

64-bit time_t workaround

--- base/events.c.orig	2023-01-17 19:26:16.000000000 +0000
+++ base/events.c
@@ -354,7 +354,7 @@ void init_timing_loop(void) {
 			if(check_delay > check_window(temp_service)) {
 				log_debug_info(DEBUGL_EVENTS, 0,
 						"  Fixing check time %lu secs too far away\n",
-						check_delay - check_window(temp_service));
+						(unsigned long)(check_delay - check_window(temp_service)));
 				fixed_services++;
 				check_delay = ranged_urand(0, check_window(temp_service));
 				log_debug_info(DEBUGL_EVENTS, 0, "  New check offset: %d\n",
@@ -506,7 +506,7 @@ void init_timing_loop(void) {
 		check_delay = mult_factor * scheduling_info.host_inter_check_delay;
 		if(check_delay > check_window(temp_host)) {
 			log_debug_info(DEBUGL_EVENTS, 1, "Fixing check time (off by %lu)\n",
-					check_delay - check_window(temp_host));
+					(unsigned long)(check_delay - check_window(temp_host)));
 			fixed_hosts++;
 			check_delay = ranged_urand(0, check_window(temp_host));
 			}

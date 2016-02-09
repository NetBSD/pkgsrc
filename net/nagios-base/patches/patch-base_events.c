$NetBSD: patch-base_events.c,v 1.2 2016/02/09 10:12:53 bouyer Exp $

64bit time_t workaround

--- base/events.c.orig	2016-02-07 21:54:30.000000000 +0100
+++ base/events.c	2016-02-07 21:55:49.000000000 +0100
@@ -354,7 +354,7 @@
 			if(check_delay > check_window(temp_service)) {
 				log_debug_info(DEBUGL_EVENTS, 0,
 						"  Fixing check time %lu secs too far away\n",
-						check_delay - check_window(temp_service));
+						(unsigned long)(check_delay - check_window(temp_service)));
 				fixed_services++;
 				check_delay = ranged_urand(0, check_window(temp_service));
 				log_debug_info(DEBUGL_EVENTS, 0, "  New check offset: %d\n",
@@ -507,7 +507,7 @@
 		check_delay = mult_factor * scheduling_info.host_inter_check_delay;
 		if(check_delay > check_window(temp_host)) {
 			log_debug_info(DEBUGL_EVENTS, 1, "Fixing check time (off by %lu)\n",
-					check_delay - check_window(temp_host));
+					(unsigned long)(check_delay - check_window(temp_host)));
 			fixed_hosts++;
 			check_delay = ranged_urand(0, check_window(temp_host));
 			}

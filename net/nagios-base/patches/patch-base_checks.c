$NetBSD: patch-base_checks.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- base/checks.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ base/checks.c	2023-01-09 06:59:06.794518822 +0900
@@ -2027,12 +2027,12 @@
 		if (expected_time < current_time) {
 
 			/* log a warning */
-			logit(NSLOG_RUNTIME_WARNING, TRUE, "Warning: The check of service '%s' on host '%s' looks like it was orphaned (results never came back; last_check=%lu; next_check=%lu).  I'm scheduling an immediate check of the service...\n", temp_service->description, temp_service->host_name, temp_service->last_check, temp_service->next_check);
+			logit(NSLOG_RUNTIME_WARNING, TRUE, "Warning: The check of service '%s' on host '%s' looks like it was orphaned (results never came back; last_check=%lu; next_check=%lu).  I'm scheduling an immediate check of the service...\n", temp_service->description, temp_service->host_name, (unsigned long)temp_service->last_check, (unsigned long)temp_service->next_check);
 
 			log_debug_info(DEBUGL_CHECKS, 1, "Service '%s' on host '%s' was orphaned, so we're scheduling an immediate check...\n", temp_service->description, temp_service->host_name);
 			log_debug_info(DEBUGL_CHECKS, 1, "  next_check=%lu (%s); last_check=%lu (%s);\n",
-						   temp_service->next_check, ctime(&temp_service->next_check),
-						   temp_service->last_check, ctime(&temp_service->last_check));
+						   (unsigned long)temp_service->next_check, ctime(&temp_service->next_check),
+						   (unsigned long)temp_service->last_check, ctime(&temp_service->last_check));
 
 			/* decrement the number of running service checks */
 			if (currently_running_service_checks > 0) {

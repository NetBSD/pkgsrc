$NetBSD: patch-cgi_cmd.c,v 1.7 2023/01/08 23:33:59 sekiya Exp $

Fix build in SunOS.
64-bit time_t workaround.

--- cgi/cmd.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ cgi/cmd.c	2023-01-09 07:06:23.042829273 +0900
@@ -1937,7 +1937,7 @@
 	if(!command_name || (strlen(command_name) > 6 && !memcmp("CHANGE", command_name, 6)))
 		return ERROR;
 
-	len = snprintf(cmd, sizeof(cmd), "[%lu] %s;", time(NULL), command_name);
+	len = snprintf(cmd, sizeof(cmd), "[%lu] %s;", (unsigned long)time(NULL), command_name);
 	if(len < 0 || len >= sizeof(cmd))
 		return ERROR;
 
@@ -2072,25 +2072,25 @@
 			break;
 
 		case CMD_DELAY_HOST_NOTIFICATION:
-			result = cmd_submitf(cmd, "%s;%lu", host_name, notification_time);
+			result = cmd_submitf(cmd, "%s;%lu", host_name, (unsigned long)notification_time);
 			break;
 
 		case CMD_DELAY_SVC_NOTIFICATION:
-			result = cmd_submitf(cmd, "%s;%s;%lu", host_name, service_desc, notification_time);
+			result = cmd_submitf(cmd, "%s;%s;%lu", host_name, service_desc, (unsigned long)notification_time);
 			break;
 
 		case CMD_SCHEDULE_SVC_CHECK:
 		case CMD_SCHEDULE_FORCED_SVC_CHECK:
 			if(force_check == TRUE)
 				cmd = CMD_SCHEDULE_FORCED_SVC_CHECK;
-			result = cmd_submitf(cmd, "%s;%s;%lu", host_name, service_desc, start_time);
+			result = cmd_submitf(cmd, "%s;%s;%lu", host_name, service_desc, (unsigned long)start_time);
 			break;
 
 		case CMD_DISABLE_NOTIFICATIONS:
 		case CMD_ENABLE_NOTIFICATIONS:
 		case CMD_SHUTDOWN_PROCESS:
 		case CMD_RESTART_PROCESS:
-			result = cmd_submitf(cmd, "%lu", scheduled_time);
+			result = cmd_submitf(cmd, "%lu", (unsigned long)scheduled_time);
 			break;
 
 		case CMD_ENABLE_HOST_SVC_CHECKS:
@@ -2105,7 +2105,7 @@
 		case CMD_SCHEDULE_HOST_SVC_CHECKS:
 			if(force_check == TRUE)
 				cmd = CMD_SCHEDULE_FORCED_HOST_SVC_CHECKS;
-			result = cmd_submitf(cmd, "%s;%lu", host_name, scheduled_time);
+			result = cmd_submitf(cmd, "%s;%lu", host_name, (unsigned long)scheduled_time);
 			break;
 
 		case CMD_ENABLE_HOST_NOTIFICATIONS:
@@ -2146,15 +2146,15 @@
 			else if(child_options == 2)
 				cmd = CMD_SCHEDULE_AND_PROPAGATE_HOST_DOWNTIME;
 
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu", host_name, start_time, end_time, fixed, triggered_by, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu", host_name, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration);
 			break;
 
 		case CMD_SCHEDULE_HOST_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu", host_name, start_time, end_time, fixed, triggered_by, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu", host_name, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration);
 			break;
 
 		case CMD_SCHEDULE_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%s;%lu;%lu;%d;%lu;%lu", host_name, service_desc, start_time, end_time, fixed, triggered_by, duration);
+			result = cmd_submitf(cmd, "%s;%s;%lu;%lu;%d;%lu;%lu", host_name, service_desc, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration);
 			break;
 
 		case CMD_DEL_HOST_DOWNTIME:
@@ -2165,7 +2165,7 @@
 		case CMD_SCHEDULE_HOST_CHECK:
 			if(force_check == TRUE)
 				cmd = CMD_SCHEDULE_FORCED_HOST_CHECK;
-			result = cmd_submitf(cmd, "%s;%lu", host_name, start_time);
+			result = cmd_submitf(cmd, "%s;%lu", host_name, (unsigned long)start_time);
 			break;
 
 		case CMD_SEND_CUSTOM_HOST_NOTIFICATION:
@@ -2203,11 +2203,11 @@
 			break;
 
 		case CMD_SCHEDULE_HOSTGROUP_HOST_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", hostgroup_name, start_time, end_time, fixed, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", hostgroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration);
 			break;
 
 		case CMD_SCHEDULE_HOSTGROUP_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", hostgroup_name, start_time, end_time, fixed, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", hostgroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration);
 			if(affect_host_and_services == TRUE)
 				result |= cmd_submitf(CMD_SCHEDULE_HOSTGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu", hostgroup_name, start_time, end_time, fixed, duration);
 			break;
@@ -2239,13 +2239,13 @@
 			break;
 
 		case CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, start_time, end_time, fixed, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration);
 			break;
 
 		case CMD_SCHEDULE_SERVICEGROUP_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, start_time, end_time, fixed, duration);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration);
 			if(affect_host_and_services == TRUE)
-				result |= cmd_submitf(CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, start_time, end_time, fixed, duration);
+				result |= cmd_submitf(CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration);
 			break;
 
 		default:

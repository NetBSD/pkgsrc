$NetBSD: patch-cgi_cmd.c,v 1.4.6.1 2016/02/08 10:12:10 bsiegert Exp $

Fix build in SunOS.
64bit time_t workaround.

--- cgi/cmd.c.orig	2014-08-12 17:00:01.000000000 +0200
+++ cgi/cmd.c	2016-02-07 22:41:29.000000000 +0100
@@ -1403,7 +1403,7 @@
 	service *temp_service;
 	host *temp_host;
 	hostgroup *temp_hostgroup;
-	comment *temp_comment;
+	my_comment *temp_comment;
 	scheduled_downtime *temp_downtime;
 	servicegroup *temp_servicegroup = NULL;
 	contact *temp_contact = NULL;
@@ -1906,7 +1906,7 @@
 	if(!command_name || (strlen(command_name) > 6 && !memcmp("CHANGE", command_name, 6)))
 		return ERROR;
 
-	len = snprintf(cmd, sizeof(cmd), "[%lu] %s;", time(NULL), command_name);
+	len = snprintf(cmd, sizeof(cmd), "[%lu] %s;", (unsigned long)time(NULL), command_name);
 	if(len < 0 || len >= sizeof(cmd))
 		return ERROR;
 
@@ -2032,25 +2032,25 @@
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
@@ -2065,7 +2065,7 @@
 		case CMD_SCHEDULE_HOST_SVC_CHECKS:
 			if(force_check == TRUE)
 				cmd = CMD_SCHEDULE_FORCED_HOST_SVC_CHECKS;
-			result = cmd_submitf(cmd, "%s;%lu", host_name, scheduled_time);
+			result = cmd_submitf(cmd, "%s;%lu", host_name, (unsigned long)scheduled_time);
 			break;
 
 		case CMD_ENABLE_HOST_NOTIFICATIONS:
@@ -2106,15 +2106,15 @@
 			else if(child_options == 2)
 				cmd = CMD_SCHEDULE_AND_PROPAGATE_HOST_DOWNTIME;
 
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, start_time, end_time, fixed, triggered_by, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration, comment_author, comment_data);
 			break;
 
 		case CMD_SCHEDULE_HOST_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, start_time, end_time, fixed, triggered_by, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration, comment_author, comment_data);
 			break;
 
 		case CMD_SCHEDULE_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, service_desc, start_time, end_time, fixed, triggered_by, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%s;%lu;%lu;%d;%lu;%lu;%s;%s", host_name, service_desc, (unsigned long)start_time, (unsigned long)end_time, fixed, triggered_by, duration, comment_author, comment_data);
 			break;
 
 		case CMD_DEL_HOST_DOWNTIME:
@@ -2125,7 +2125,7 @@
 		case CMD_SCHEDULE_HOST_CHECK:
 			if(force_check == TRUE)
 				cmd = CMD_SCHEDULE_FORCED_HOST_CHECK;
-			result = cmd_submitf(cmd, "%s;%lu", host_name, start_time);
+			result = cmd_submitf(cmd, "%s;%lu", host_name, (unsigned long)start_time);
 			break;
 
 		case CMD_SEND_CUSTOM_HOST_NOTIFICATION:
@@ -2163,13 +2163,13 @@
 			break;
 
 		case CMD_SCHEDULE_HOSTGROUP_HOST_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			break;
 
 		case CMD_SCHEDULE_HOSTGROUP_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			if(affect_host_and_services == TRUE)
-				result |= cmd_submitf(CMD_SCHEDULE_HOSTGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+				result |= cmd_submitf(CMD_SCHEDULE_HOSTGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu;%s;%s", hostgroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			break;
 
 
@@ -2199,13 +2199,13 @@
 			break;
 
 		case CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			break;
 
 		case CMD_SCHEDULE_SERVICEGROUP_SVC_DOWNTIME:
-			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+			result = cmd_submitf(cmd, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			if(affect_host_and_services == TRUE)
-				result |= cmd_submitf(CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, start_time, end_time, fixed, duration, comment_author, comment_data);
+				result |= cmd_submitf(CMD_SCHEDULE_SERVICEGROUP_HOST_DOWNTIME, "%s;%lu;%lu;%d;0;%lu;%s;%s", servicegroup_name, (unsigned long)start_time, (unsigned long)end_time, fixed, duration, comment_author, comment_data);
 			break;
 
 		default:

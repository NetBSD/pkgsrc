$NetBSD: patch-xdata_xrddefault.c,v 1.2 2016/02/07 21:52:06 bouyer Exp $

Fix build in SunOS.
64bit time_t workaround.

--- xdata/xrddefault.c.orig	2014-08-12 17:00:01.000000000 +0200
+++ xdata/xrddefault.c	2016-02-07 22:01:56.000000000 +0100
@@ -87,7 +87,7 @@
 	host *temp_host = NULL;
 	service *temp_service = NULL;
 	contact *temp_contact = NULL;
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	scheduled_downtime *temp_downtime = NULL;
 	int x = 0;
 	int fd = 0;
@@ -151,9 +151,9 @@
 
 	/* write file info */
 	fprintf(fp, "info {\n");
-	fprintf(fp, "created=%lu\n", current_time);
+	fprintf(fp, "created=%lu\n", (unsigned long)current_time);
 	fprintf(fp, "version=%s\n", PROGRAM_VERSION);
-	fprintf(fp, "last_update_check=%lu\n", last_update_check);
+	fprintf(fp, "last_update_check=%lu\n", (unsigned long)last_update_check);
 	fprintf(fp, "update_available=%d\n", update_available);
 	fprintf(fp, "update_uid=%lu\n", update_uid);
 	fprintf(fp, "last_version=%s\n", (last_program_version == NULL) ? "" : last_program_version);
@@ -209,22 +209,22 @@
 		fprintf(fp, "plugin_output=%s\n", (temp_host->plugin_output == NULL) ? "" : temp_host->plugin_output);
 		fprintf(fp, "long_plugin_output=%s\n", (temp_host->long_plugin_output == NULL) ? "" : temp_host->long_plugin_output);
 		fprintf(fp, "performance_data=%s\n", (temp_host->perf_data == NULL) ? "" : temp_host->perf_data);
-		fprintf(fp, "last_check=%lu\n", temp_host->last_check);
-		fprintf(fp, "next_check=%lu\n", temp_host->next_check);
+		fprintf(fp, "last_check=%lu\n", (unsigned long)temp_host->last_check);
+		fprintf(fp, "next_check=%lu\n", (unsigned long)temp_host->next_check);
 		fprintf(fp, "check_options=%d\n", temp_host->check_options);
 		fprintf(fp, "current_attempt=%d\n", temp_host->current_attempt);
 		fprintf(fp, "max_attempts=%d\n", temp_host->max_attempts);
 		fprintf(fp, "normal_check_interval=%f\n", temp_host->check_interval);
 		fprintf(fp, "retry_check_interval=%f\n", temp_host->check_interval);
 		fprintf(fp, "state_type=%d\n", temp_host->state_type);
-		fprintf(fp, "last_state_change=%lu\n", temp_host->last_state_change);
-		fprintf(fp, "last_hard_state_change=%lu\n", temp_host->last_hard_state_change);
-		fprintf(fp, "last_time_up=%lu\n", temp_host->last_time_up);
-		fprintf(fp, "last_time_down=%lu\n", temp_host->last_time_down);
-		fprintf(fp, "last_time_unreachable=%lu\n", temp_host->last_time_unreachable);
+		fprintf(fp, "last_state_change=%lu\n", (unsigned long)temp_host->last_state_change);
+		fprintf(fp, "last_hard_state_change=%lu\n", (unsigned long)temp_host->last_hard_state_change);
+		fprintf(fp, "last_time_up=%lu\n", (unsigned long)temp_host->last_time_up);
+		fprintf(fp, "last_time_down=%lu\n", (unsigned long)temp_host->last_time_down);
+		fprintf(fp, "last_time_unreachable=%lu\n", (unsigned long)temp_host->last_time_unreachable);
 		fprintf(fp, "notified_on_down=%d\n", flag_isset(temp_host->notified_on, OPT_DOWN));
 		fprintf(fp, "notified_on_unreachable=%d\n", flag_isset(temp_host->notified_on, OPT_UNREACHABLE));
-		fprintf(fp, "last_notification=%lu\n", temp_host->last_notification);
+		fprintf(fp, "last_notification=%lu\n", (unsigned long)temp_host->last_notification);
 		fprintf(fp, "current_notification_number=%d\n", temp_host->current_notification_number);
 		fprintf(fp, "current_notification_id=%lu\n", temp_host->current_notification_id);
 		fprintf(fp, "notifications_enabled=%d\n", temp_host->notifications_enabled);
@@ -281,24 +281,24 @@
 		fprintf(fp, "normal_check_interval=%f\n", temp_service->check_interval);
 		fprintf(fp, "retry_check_interval=%f\n", temp_service->retry_interval);
 		fprintf(fp, "state_type=%d\n", temp_service->state_type);
-		fprintf(fp, "last_state_change=%lu\n", temp_service->last_state_change);
-		fprintf(fp, "last_hard_state_change=%lu\n", temp_service->last_hard_state_change);
-		fprintf(fp, "last_time_ok=%lu\n", temp_service->last_time_ok);
-		fprintf(fp, "last_time_warning=%lu\n", temp_service->last_time_warning);
-		fprintf(fp, "last_time_unknown=%lu\n", temp_service->last_time_unknown);
-		fprintf(fp, "last_time_critical=%lu\n", temp_service->last_time_critical);
+		fprintf(fp, "last_state_change=%lu\n", (unsigned long)temp_service->last_state_change);
+		fprintf(fp, "last_hard_state_change=%lu\n", (unsigned long)temp_service->last_hard_state_change);
+		fprintf(fp, "last_time_ok=%lu\n", (unsigned long)temp_service->last_time_ok);
+		fprintf(fp, "last_time_warning=%lu\n", (unsigned long)temp_service->last_time_warning);
+		fprintf(fp, "last_time_unknown=%lu\n", (unsigned long)temp_service->last_time_unknown);
+		fprintf(fp, "last_time_critical=%lu\n", (unsigned long)temp_service->last_time_critical);
 		fprintf(fp, "plugin_output=%s\n", (temp_service->plugin_output == NULL) ? "" : temp_service->plugin_output);
 		fprintf(fp, "long_plugin_output=%s\n", (temp_service->long_plugin_output == NULL) ? "" : temp_service->long_plugin_output);
 		fprintf(fp, "performance_data=%s\n", (temp_service->perf_data == NULL) ? "" : temp_service->perf_data);
-		fprintf(fp, "last_check=%lu\n", temp_service->last_check);
-		fprintf(fp, "next_check=%lu\n", temp_service->next_check);
+		fprintf(fp, "last_check=%lu\n", (unsigned long)temp_service->last_check);
+		fprintf(fp, "next_check=%lu\n", (unsigned long)temp_service->next_check);
 		fprintf(fp, "check_options=%d\n", temp_service->check_options);
 		fprintf(fp, "notified_on_unknown=%d\n", flag_isset(temp_service->notified_on, OPT_UNKNOWN));
 		fprintf(fp, "notified_on_warning=%d\n", flag_isset(temp_service->notified_on, OPT_WARNING));
 		fprintf(fp, "notified_on_critical=%d\n", flag_isset(temp_service->notified_on, OPT_CRITICAL));
 		fprintf(fp, "current_notification_number=%d\n", temp_service->current_notification_number);
 		fprintf(fp, "current_notification_id=%lu\n", temp_service->current_notification_id);
-		fprintf(fp, "last_notification=%lu\n", temp_service->last_notification);
+		fprintf(fp, "last_notification=%lu\n", (unsigned long)temp_service->last_notification);
 		fprintf(fp, "notifications_enabled=%d\n", temp_service->notifications_enabled);
 		fprintf(fp, "active_checks_enabled=%d\n", temp_service->checks_enabled);
 		fprintf(fp, "passive_checks_enabled=%d\n", temp_service->accept_passive_checks);
@@ -336,8 +336,8 @@
 		fprintf(fp, "modified_service_attributes=%lu\n", (temp_contact->modified_service_attributes & ~contact_service_attribute_mask));
 		fprintf(fp, "host_notification_period=%s\n", (temp_contact->host_notification_period == NULL) ? "" : temp_contact->host_notification_period);
 		fprintf(fp, "service_notification_period=%s\n", (temp_contact->service_notification_period == NULL) ? "" : temp_contact->service_notification_period);
-		fprintf(fp, "last_host_notification=%lu\n", temp_contact->last_host_notification);
-		fprintf(fp, "last_service_notification=%lu\n", temp_contact->last_service_notification);
+		fprintf(fp, "last_host_notification=%lu\n", (unsigned long)temp_contact->last_host_notification);
+		fprintf(fp, "last_service_notification=%lu\n", (unsigned long)temp_contact->last_service_notification);
 		fprintf(fp, "host_notifications_enabled=%d\n", temp_contact->host_notifications_enabled);
 		fprintf(fp, "service_notifications_enabled=%d\n", temp_contact->service_notifications_enabled);
 
@@ -364,9 +364,9 @@
 		fprintf(fp, "comment_id=%lu\n", temp_comment->comment_id);
 		fprintf(fp, "source=%d\n", temp_comment->source);
 		fprintf(fp, "persistent=%d\n", temp_comment->persistent);
-		fprintf(fp, "entry_time=%lu\n", temp_comment->entry_time);
+		fprintf(fp, "entry_time=%lu\n", (unsigned long)temp_comment->entry_time);
 		fprintf(fp, "expires=%d\n", temp_comment->expires);
-		fprintf(fp, "expire_time=%lu\n", temp_comment->expire_time);
+		fprintf(fp, "expire_time=%lu\n", (unsigned long)temp_comment->expire_time);
 		fprintf(fp, "author=%s\n", temp_comment->author);
 		fprintf(fp, "comment_data=%s\n", temp_comment->comment_data);
 		fprintf(fp, "}\n");
@@ -384,10 +384,10 @@
 			fprintf(fp, "service_description=%s\n", temp_downtime->service_description);
 		fprintf(fp, "comment_id=%lu\n", temp_downtime->comment_id);
 		fprintf(fp, "downtime_id=%lu\n", temp_downtime->downtime_id);
-		fprintf(fp, "entry_time=%lu\n", temp_downtime->entry_time);
-		fprintf(fp, "start_time=%lu\n", temp_downtime->start_time);
-		fprintf(fp, "flex_downtime_start=%lu\n", temp_downtime->flex_downtime_start);
-		fprintf(fp, "end_time=%lu\n", temp_downtime->end_time);
+		fprintf(fp, "entry_time=%lu\n", (unsigned long)temp_downtime->entry_time);
+		fprintf(fp, "start_time=%lu\n", (unsigned long)temp_downtime->start_time);
+		fprintf(fp, "flex_downtime_start=%lu\n", (unsigned long)temp_downtime->flex_downtime_start);
+		fprintf(fp, "end_time=%lu\n", (unsigned long)temp_downtime->end_time);
 		fprintf(fp, "triggered_by=%lu\n", temp_downtime->triggered_by);
 		fprintf(fp, "fixed=%d\n", temp_downtime->fixed);
 		fprintf(fp, "duration=%lu\n", temp_downtime->duration);

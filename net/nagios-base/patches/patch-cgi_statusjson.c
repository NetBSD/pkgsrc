$NetBSD: patch-cgi_statusjson.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- cgi/statusjson.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ cgi/statusjson.c
@@ -63,7 +63,7 @@ extern service *service_list;
 extern contact *contact_list;
 #endif
 extern servicestatus *servicestatus_list;
-extern comment *comment_list;
+extern my_comment *comment_list;
 extern scheduled_downtime *scheduled_downtime_list;
 
 /* Program status variables */
@@ -717,7 +717,7 @@ json_object *json_status_service_selecto
 		time_t, time_t, char *, char *, char *, contactgroup *, timeperiod *,
 		timeperiod *, command *, command *);
 
-int json_status_comment_passes_selection(comment *, int, time_t, time_t,
+int json_status_comment_passes_selection(my_comment *, int, time_t, time_t,
 		unsigned, unsigned, unsigned, unsigned, char *, char *);
 json_object *json_status_comment_selectors(unsigned, int, int, int, time_t, 
 		time_t, unsigned, unsigned, unsigned, unsigned, char *, char *);
@@ -1824,7 +1824,7 @@ int validate_arguments(json_object *json
 	timeperiod *temp_timeperiod = NULL;
 	command *temp_command = NULL;
 	contact *temp_contact = NULL;
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	scheduled_downtime *temp_downtime = NULL;
 	authdata *authinfo = NULL; /* Currently always NULL because
 									get_authentication_information() hasn't
@@ -3568,7 +3568,7 @@ void json_status_service_details(json_ob
 #endif
 	}
 
-int json_status_comment_passes_selection(comment *temp_comment, int time_field, 
+int json_status_comment_passes_selection(my_comment *temp_comment, int time_field, 
 		time_t start_time, time_t end_time, unsigned comment_types,
 		unsigned entry_types, unsigned persistence, unsigned expiring,
 		char *host_name, char *service_description) {
@@ -3743,7 +3743,7 @@ json_object *json_status_commentcount(un
 		char *host_name, char *service_description) {
 
 	json_object *json_data;
-	comment *temp_comment;
+	my_comment *temp_comment;
 	int count = 0;
 
 	json_data = json_new_object();
@@ -3777,7 +3777,7 @@ json_object *json_status_commentlist(uns
 	json_object *json_commentlist_object = NULL;
 	json_object *json_commentlist_array = NULL;
 	json_object *json_comment_details;
-	comment *temp_comment;
+	my_comment *temp_comment;
 	int current = 0;
 	int counted = 0;
 	char *buf;
@@ -3835,7 +3835,7 @@ json_object *json_status_commentlist(uns
 	return json_data;
 	}
 
-json_object *json_status_comment(unsigned format_options, comment *temp_comment) {
+json_object *json_status_comment(unsigned format_options, my_comment *temp_comment) {
 
 	json_object *json_comment = json_new_object();
 	json_object *json_details = json_new_object();
@@ -3849,7 +3849,7 @@ json_object *json_status_comment(unsigne
 	}
 
 void json_status_comment_details(json_object *json_details, 
-		unsigned format_options, comment *temp_comment) {
+		unsigned format_options, my_comment *temp_comment) {
 
 	json_object_append_integer(json_details, "comment_id", 
 			temp_comment->comment_id);

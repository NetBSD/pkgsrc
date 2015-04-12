$NetBSD: patch-cgi_extinfo.c,v 1.3 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- cgi/extinfo.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ cgi/extinfo.c
@@ -1739,7 +1739,7 @@ void show_all_comments(void) {
 	const char *bg_class = "";
 	int odd = 0;
 	char date_time[MAX_DATETIME_LENGTH];
-	comment *temp_comment;
+	my_comment *temp_comment;
 	host *temp_host;
 	service *temp_service;
 	char *comment_type;
@@ -2420,7 +2420,7 @@ void display_comments(int type) {
 	const char *bg_class = "";
 	int odd = 1;
 	char date_time[MAX_DATETIME_LENGTH];
-	comment *temp_comment;
+	my_comment *temp_comment;
 	char *comment_type;
 	char expire_time[MAX_DATETIME_LENGTH];
 

$NetBSD: patch-cgi_cmd.c,v 1.4 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- cgi/cmd.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ cgi/cmd.c
@@ -1403,7 +1403,7 @@ void commit_command_data(int cmd) {
 	service *temp_service;
 	host *temp_host;
 	hostgroup *temp_hostgroup;
-	comment *temp_comment;
+	my_comment *temp_comment;
 	scheduled_downtime *temp_downtime;
 	servicegroup *temp_servicegroup = NULL;
 	contact *temp_contact = NULL;

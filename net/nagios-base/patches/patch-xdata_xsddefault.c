$NetBSD: patch-xdata_xsddefault.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- xdata/xsddefault.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ xdata/xsddefault.c
@@ -118,7 +118,7 @@ int xsddefault_save_status_data(void) {
 	host *temp_host = NULL;
 	service *temp_service = NULL;
 	contact *temp_contact = NULL;
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	scheduled_downtime *temp_downtime = NULL;
 	time_t current_time;
 	int fd = 0;

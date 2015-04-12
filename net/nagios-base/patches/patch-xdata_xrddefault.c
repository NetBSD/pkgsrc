$NetBSD: patch-xdata_xrddefault.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- xdata/xrddefault.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ xdata/xrddefault.c
@@ -87,7 +87,7 @@ int xrddefault_save_state_information(vo
 	host *temp_host = NULL;
 	service *temp_service = NULL;
 	contact *temp_contact = NULL;
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 	scheduled_downtime *temp_downtime = NULL;
 	int x = 0;
 	int fd = 0;

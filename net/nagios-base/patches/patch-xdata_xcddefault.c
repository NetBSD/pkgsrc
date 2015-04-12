$NetBSD: patch-xdata_xcddefault.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- xdata/xcddefault.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ xdata/xcddefault.c
@@ -40,7 +40,7 @@
 
 /* initialize comment data */
 int xcddefault_initialize_comment_data(void) {
-	comment *temp_comment = NULL;
+	my_comment *temp_comment = NULL;
 
 	/* find the new starting index for comment id if its missing*/
 	if(next_comment_id == 0L) {

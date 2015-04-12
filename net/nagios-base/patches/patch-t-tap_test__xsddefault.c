$NetBSD: patch-t-tap_test__xsddefault.c,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- t-tap/test_xsddefault.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ t-tap/test_xsddefault.c
@@ -41,7 +41,7 @@
 #include "../include/skiplist.h"
 #include "tap.h"
 
-extern comment *comment_list;
+extern my_comment *comment_list;
 extern scheduled_downtime *scheduled_downtime_list;
 
 int main(int argc, char **argv) {
@@ -49,7 +49,7 @@ int main(int argc, char **argv) {
 	int c;
 	int last_id;
 	time_t last_time;
-	comment *temp_comment;
+	my_comment *temp_comment;
 	scheduled_downtime *temp_downtime;
 
 	plan_tests(7);

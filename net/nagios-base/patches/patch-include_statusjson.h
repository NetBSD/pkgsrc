$NetBSD: patch-include_statusjson.h,v 1.1 2015/04/12 23:33:06 rodent Exp $

Fix build in SunOS.

--- include/statusjson.h.orig	2014-08-12 15:00:01.000000000 +0000
+++ include/statusjson.h
@@ -123,7 +123,7 @@ typedef struct status_json_cgi_data_stru
 	/* ID of comment for which details should be returned */
 	int			comment_id;
 	/* Comment whose id is comment_id */
-	comment *	comment;
+	my_comment *	comment;
 	/* ID of downtime for which details should be returned */
 	int		 	downtime_id;
 	/* Downtime whose id is downtime_id */
@@ -260,8 +260,8 @@ extern json_object *json_status_commentc
 		unsigned, unsigned, unsigned, unsigned, char *, char *);
 extern json_object *json_status_commentlist(unsigned, int, int, int, int, 
 		time_t, time_t, unsigned, unsigned, unsigned, unsigned, char *, char *);
-extern json_object *json_status_comment(unsigned, comment *);
-extern void json_status_comment_details(json_object *, unsigned, comment *);
+extern json_object *json_status_comment(unsigned, my_comment *);
+extern void json_status_comment_details(json_object *, unsigned, my_comment *);
 
 extern json_object *json_status_downtimecount(unsigned, int, time_t, time_t, 
 		unsigned, unsigned, unsigned, int, unsigned, char *, char *);

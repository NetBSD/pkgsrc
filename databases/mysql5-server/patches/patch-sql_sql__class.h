$NetBSD: patch-sql_sql__class.h,v 1.1 2011/08/02 16:15:08 taca Exp $

* Handling of time_t: http://lists.mysql.com/commits/128103

--- sql/sql_class.h.orig	2011-01-25 11:27:51.000000000 +0000
+++ sql/sql_class.h
@@ -1710,7 +1710,7 @@ public:
   /*TODO: this will be obsolete when we have support for 64 bit my_time_t */
   inline bool	is_valid_time() 
   { 
-    return (start_time < (time_t) MY_TIME_T_MAX); 
+    return (IS_VALID_TIME_T(start_time));
   }
   inline void	insert_id(ulonglong id_arg)
   {

$NetBSD: patch-driver_mysql__resultbind.cpp,v 1.2 2017/01/12 12:24:09 adam Exp $

https://bugs.mysql.com/bug.php?id=80539

--- driver/mysql_resultbind.cpp.orig	2016-12-14 09:58:54.000000000 +0000
+++ driver/mysql_resultbind.cpp
@@ -88,8 +88,8 @@ static struct st_buffer_size_type
     case MYSQL_TYPE_VAR_STRING:
 #if LIBMYSQL_VERSION_ID > 50700
     case MYSQL_TYPE_JSON:
-      return st_buffer_size_type(new char[field->max_length + 1], field->max_length + 1, field->type);
 #endif //LIBMYSQL_VERSION_ID > 50700
+      return st_buffer_size_type(new char[field->max_length + 1], field->max_length + 1, field->type);
 
     case MYSQL_TYPE_DECIMAL:
     case MYSQL_TYPE_NEWDECIMAL:

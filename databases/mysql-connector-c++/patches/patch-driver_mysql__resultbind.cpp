$NetBSD: patch-driver_mysql__resultbind.cpp,v 1.1 2016/03/08 15:40:02 wiz Exp $

https://bugs.mysql.com/bug.php?id=80539

--- driver/mysql_resultbind.cpp.orig	2016-01-12 18:42:38.000000000 +0000
+++ driver/mysql_resultbind.cpp
@@ -86,7 +86,9 @@ static struct st_buffer_size_type
     case MYSQL_TYPE_BLOB:
     case MYSQL_TYPE_STRING:
     case MYSQL_TYPE_VAR_STRING:
+#ifdef MYSQL_TYPE_JSON
     case MYSQL_TYPE_JSON:
+#endif
       return st_buffer_size_type(new char[field->max_length + 1], field->max_length + 1, field->type);
 
     case MYSQL_TYPE_DECIMAL:

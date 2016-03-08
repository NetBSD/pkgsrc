$NetBSD: patch-driver_mysql__util.cpp,v 1.1 2016/03/08 15:40:02 wiz Exp $

https://bugs.mysql.com/bug.php?id=80539

--- driver/mysql_util.cpp.orig	2016-01-12 18:42:38.000000000 +0000
+++ driver/mysql_util.cpp
@@ -431,8 +431,10 @@ mysql_type_to_datatype(const MYSQL_FIELD
       return sql::DataType::SET;
     case MYSQL_TYPE_GEOMETRY:
       return sql::DataType::GEOMETRY;
+#ifdef MYSQL_TYPE_JSON
     case MYSQL_TYPE_JSON:
       return sql::DataType::JSON;
+#endif
     default:
       return sql::DataType::UNKNOWN;
   }
@@ -645,8 +647,10 @@ mysql_type_to_string(const MYSQL_FIELD *
       return "SET";
     case MYSQL_TYPE_GEOMETRY:
       return "GEOMETRY";
+#ifdef MYSQL_TYPE_JSON
     case MYSQL_TYPE_JSON:
       return "JSON";
+#endif
     default:
       return "UNKNOWN";
   }

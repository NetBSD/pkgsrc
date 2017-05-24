$NetBSD: patch-client_mysql.cc,v 1.1 2017/05/24 15:28:25 jperkin Exp $

Pointer fix.

--- client/mysql.cc.orig	2017-04-27 07:12:30.000000000 +0000
+++ client/mysql.cc
@@ -2666,7 +2666,7 @@ You can turn off this feature to get a q
         mysql_free_result(fields);
         break;
       }
-      field_names[i][num_fields*2]= '\0';
+      *field_names[i][num_fields*2]= '\0';
       j=0;
       while ((sql_field=mysql_fetch_field(fields)))
       {

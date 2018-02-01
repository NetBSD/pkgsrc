$NetBSD: patch-client_mysql.cc,v 1.1 2018/02/01 23:14:55 jperkin Exp $

Compilation warning fix from upstream.

--- client/mysql.cc.orig	2013-11-04 18:52:27.000000000 +0000
+++ client/mysql.cc
@@ -2684,7 +2684,7 @@ You can turn off this feature to get a q
         mysql_free_result(fields);
         break;
       }
-      field_names[i][num_fields*2]= '\0';
+      field_names[i][num_fields*2]= NULL;
       j=0;
       while ((sql_field=mysql_fetch_field(fields)))
       {

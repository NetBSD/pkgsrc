$NetBSD: patch-client_mysql.cc,v 1.2 2017/06/19 12:07:50 jperkin Exp $

Compilation warning fix from upstream.

--- client/mysql.cc.orig	2017-04-27 07:12:30.000000000 +0000
+++ client/mysql.cc
@@ -2666,7 +2666,7 @@ You can turn off this feature to get a q
         mysql_free_result(fields);
         break;
       }
-      field_names[i][num_fields*2]= '\0';
+      field_names[i][num_fields*2]= NULL;
       j=0;
       while ((sql_field=mysql_fetch_field(fields)))
       {

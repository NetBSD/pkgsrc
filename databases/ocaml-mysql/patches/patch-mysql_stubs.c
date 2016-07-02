$NetBSD: patch-mysql_stubs.c,v 1.1 2016/07/02 09:42:14 jaapb Exp $

Use C99 int64_t (patch from upstream)
--- mysql_stubs.c.orig	2015-03-10 02:55:27.000000000 +0000
+++ mysql_stubs.c
@@ -507,15 +507,15 @@ db_fetch (value result)
 }
 
 EXTERNAL value
-db_to_row(value result, value offset) {
-  int64 off = Int64_val(offset);
+db_to_row(value result, value offset){
+  int64_t off = Int64_val(offset);
   MYSQL_RES *res;
 
   res = RESval(result);
   if (!res) 
     mysqlfailwith("Mysql.to_row: result did not return fetchable data");
 
-  if (off < 0 || off > (int64)mysql_num_rows(res)-1)
+  if (off < 0 || off > (int64_t)mysql_num_rows(res)-1)
     invalid_argument("Mysql.to_row: offset out of range");
 
   mysql_data_seek(res, off);
@@ -640,13 +640,13 @@ db_size(value result)
 {
   CAMLparam1(result);
   MYSQL_RES *res;
-  int64 size;
+  int64_t size;
 
   res = RESval(result);
   if (!res)
     size = 0;
   else
-    size = (int64)(mysql_num_rows(res));
+    size = (int64_t)(mysql_num_rows(res));
   
   CAMLreturn(copy_int64(size));
 }

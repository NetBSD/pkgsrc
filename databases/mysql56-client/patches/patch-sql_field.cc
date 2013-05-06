$NetBSD: patch-sql_field.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/field.cc.orig	2013-04-05 12:27:18.000000000 +0000
+++ sql/field.cc
@@ -1855,7 +1855,7 @@ type_conversion_status Field::store_time
 
 bool Field::optimize_range(uint idx, uint part)
 {
-  return test(table->file->index_flags(idx, part, 1) & HA_READ_RANGE);
+  return my_test(table->file->index_flags(idx, part, 1) & HA_READ_RANGE);
 }
 
 
@@ -9514,7 +9514,7 @@ void Create_field::create_length_to_inte
     {
       pack_length= length / 8;
       /* We need one extra byte to store the bits we save among the null bits */
-      key_length= pack_length + test(length & 7);
+      key_length= pack_length + my_test(length & 7);
     }
     break;
   case MYSQL_TYPE_NEWDECIMAL:

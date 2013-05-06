$NetBSD: patch-sql_key.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/key.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/key.cc
@@ -123,7 +123,7 @@ void key_copy(uchar *to_key, uchar *from
   {
     if (key_part->null_bit)
     {
-      *to_key++= test(from_record[key_part->null_offset] &
+      *to_key++= my_test(from_record[key_part->null_offset] &
 		   key_part->null_bit);
       key_length--;
     }
@@ -299,7 +299,7 @@ bool key_cmp_if_same(TABLE *table,const 
 
     if (key_part->null_bit)
     {
-      if (*key != test(table->record[0][key_part->null_offset] & 
+      if (*key != my_test(table->record[0][key_part->null_offset] & 
 		       key_part->null_bit))
 	return 1;
       if (*key)
@@ -438,7 +438,7 @@ void key_unpack(String *to, TABLE *table
       }
     }
     field_unpack(to, key_part->field, table->record[0], key_part->length,
-                 test(key_part->key_part_flag & HA_PART_KEY_SEG));
+                 my_test(key_part->key_part_flag & HA_PART_KEY_SEG));
   }
   dbug_tmp_restore_column_map(table->read_set, old_map);
   DBUG_VOID_RETURN;

$NetBSD: patch-sql_item.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/item.cc.orig	2013-04-05 12:27:18.000000000 +0000
+++ sql/item.cc
@@ -2545,7 +2545,7 @@ void Item_field::set_field(Field *field_
   field_name= field_par->field_name;
   db_name= field_par->table->s->db.str;
   alias_name_used= field_par->table->alias_name_used;
-  unsigned_flag=test(field_par->flags & UNSIGNED_FLAG);
+  unsigned_flag=my_test(field_par->flags & UNSIGNED_FLAG);
   collation.set(field_par->charset(), field_par->derivation(),
                 field_par->repertoire());
   fix_char_length(field_par->char_length());

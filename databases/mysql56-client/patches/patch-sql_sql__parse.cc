$NetBSD: patch-sql_sql__parse.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_parse.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_parse.cc
@@ -6427,7 +6427,7 @@ TABLE_LIST *st_select_lex::add_table_to_
   if (!table)
     DBUG_RETURN(0);				// End of memory
   alias_str= alias ? alias->str : table->table.str;
-  if (!test(table_options & TL_OPTION_ALIAS))
+  if (!my_test(table_options & TL_OPTION_ALIAS))
   {
     enum_ident_name_check ident_check_status=
       check_table_name(table->table.str, table->table.length, FALSE);
@@ -6477,10 +6477,10 @@ TABLE_LIST *st_select_lex::add_table_to_
   ptr->table_name=table->table.str;
   ptr->table_name_length=table->table.length;
   ptr->lock_type=   lock_type;
-  ptr->updating=    test(table_options & TL_OPTION_UPDATING);
+  ptr->updating=    my_test(table_options & TL_OPTION_UPDATING);
   /* TODO: remove TL_OPTION_FORCE_INDEX as it looks like it's not used */
-  ptr->force_index= test(table_options & TL_OPTION_FORCE_INDEX);
-  ptr->ignore_leaves= test(table_options & TL_OPTION_IGNORE_LEAVES);
+  ptr->force_index= my_test(table_options & TL_OPTION_FORCE_INDEX);
+  ptr->ignore_leaves= my_test(table_options & TL_OPTION_IGNORE_LEAVES);
   ptr->derived=	    table->sel;
   if (!ptr->derived && is_infoschema_db(ptr->db, ptr->db_length))
   {
@@ -6571,7 +6571,7 @@ TABLE_LIST *st_select_lex::add_table_to_
   lex->add_to_query_tables(ptr);
 
   // Pure table aliases do not need to be locked:
-  if (!test(table_options & TL_OPTION_ALIAS))
+  if (!my_test(table_options & TL_OPTION_ALIAS))
   {
     ptr->mdl_request.init(MDL_key::TABLE, ptr->db, ptr->table_name, mdl_type,
                           MDL_TRANSACTION);

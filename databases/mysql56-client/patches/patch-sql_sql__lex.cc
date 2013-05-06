$NetBSD: patch-sql_sql__lex.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_lex.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_lex.cc
@@ -247,7 +247,7 @@ Lex_input_stream::reset(char *buffer, un
   m_cpp_utf8_processed_ptr= NULL;
   next_state= MY_LEX_START;
   found_semicolon= NULL;
-  ignore_space= test(m_thd->variables.sql_mode & MODE_IGNORE_SPACE);
+  ignore_space= my_test(m_thd->variables.sql_mode & MODE_IGNORE_SPACE);
   stmt_prepare_mode= FALSE;
   multi_statements= TRUE;
   in_comment=NO_COMMENT;
@@ -3368,7 +3368,7 @@ TABLE_LIST *LEX::unlink_first_table(bool
     /*
       and from local list if it is not empty
     */
-    if ((*link_to_local= test(select_lex.table_list.first)))
+    if ((*link_to_local= my_test(select_lex.table_list.first)))
     {
       select_lex.context.table_list= 
         select_lex.context.first_name_resolution_table= first->next_local;

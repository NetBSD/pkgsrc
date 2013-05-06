$NetBSD: patch-sql_sql__load.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_load.cc.orig	2013-04-05 12:27:18.000000000 +0000
+++ sql/sql_load.cc
@@ -475,7 +475,7 @@ int mysql_load(THD *thd,sql_exchange *ex
     }
   }
 
-  if (!(error=test(read_info.error)))
+  if (!(error=my_test(read_info.error)))
   {
 
     table->next_number_field=table->found_next_number_field;
@@ -908,7 +908,7 @@ read_fixed_length(THD *thd, COPY_INFO &i
     thd->get_stmt_da()->inc_current_row_for_warning();
 continue_loop:;
   }
-  DBUG_RETURN(test(read_info.error));
+  DBUG_RETURN(my_test(read_info.error));
 }
 
 
@@ -1118,7 +1118,7 @@ read_sep_field(THD *thd, COPY_INFO &info
     thd->get_stmt_da()->inc_current_row_for_warning();
 continue_loop:;
   }
-  DBUG_RETURN(test(read_info.error));
+  DBUG_RETURN(my_test(read_info.error));
 }
 
 
@@ -1280,7 +1280,7 @@ read_xml_field(THD *thd, COPY_INFO &info
     thd->get_stmt_da()->inc_current_row_for_warning();
     continue_loop:;
   }
-  DBUG_RETURN(test(read_info.error) || thd->is_error());
+  DBUG_RETURN(my_test(read_info.error) || thd->is_error());
 } /* load xml end */
 
 

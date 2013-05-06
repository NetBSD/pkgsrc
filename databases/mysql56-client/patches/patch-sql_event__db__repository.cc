$NetBSD: patch-sql_event__db__repository.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/event_db_repository.cc.orig	2013-04-05 12:27:18.000000000 +0000
+++ sql/event_db_repository.cc
@@ -469,7 +469,7 @@ Event_db_repository::index_read_for_db_f
 end:
   event_table->file->ha_index_end();
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
@@ -743,7 +743,7 @@ end:
   thd->mdl_context.rollback_to_savepoint(mdl_savepoint);
 
   thd->variables.sql_mode= saved_mode;
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
@@ -858,7 +858,7 @@ end:
   thd->mdl_context.rollback_to_savepoint(mdl_savepoint);
 
   thd->variables.sql_mode= saved_mode;
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
@@ -918,7 +918,7 @@ end:
   close_thread_tables(thd);
   thd->mdl_context.rollback_to_savepoint(mdl_savepoint);
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
@@ -1153,7 +1153,7 @@ end:
   if (save_binlog_row_based)
     thd->set_current_stmt_binlog_format_row();
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 
@@ -1230,7 +1230,7 @@ Event_db_repository::check_system_tables
     close_mysql_tables(thd);
   }
 
-  DBUG_RETURN(test(ret));
+  DBUG_RETURN(my_test(ret));
 }
 
 /**

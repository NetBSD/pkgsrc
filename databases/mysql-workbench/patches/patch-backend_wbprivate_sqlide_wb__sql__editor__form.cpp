$NetBSD: patch-backend_wbprivate_sqlide_wb__sql__editor__form.cpp,v 1.1 2015/07/07 11:45:52 joerg Exp $

Can't use dynamic_cast as the type information is normally not present.

--- backend/wbprivate/sqlide/wb_sql_editor_form.cpp.orig	2015-06-28 18:41:49.000000000 +0000
+++ backend/wbprivate/sqlide/wb_sql_editor_form.cpp
@@ -1728,7 +1728,7 @@ grt::StringRef Db_sql_editor::do_exec_sq
               goto stop_processing_sql_script;
           }
 
-          sql::mysql::MySQL_Connection* mysql_connection = dynamic_cast<sql::mysql::MySQL_Connection*>(dbc_statement->getConnection());
+          sql::mysql::MySQL_Connection* mysql_connection = reinterpret_cast<sql::mysql::MySQL_Connection*>(dbc_statement->getConnection());
           sql::SQLString last_statement_info;
           if (mysql_connection != NULL)
             last_statement_info = mysql_connection->getLastStatementInfo();

$NetBSD: patch-mysql.c,v 1.2 2021/02/14 14:55:42 taca Exp $

* Fix build with ruby24 and ruby30.

--- mysql.c.orig	2010-02-11 10:42:54.000000000 +0000
+++ mysql.c
@@ -875,12 +875,12 @@ static VALUE stmt_init(VALUE obj)
     MYSQL *m = GetHandler(obj);
     MYSQL_STMT *s;
     struct mysql_stmt* stmt;
-    my_bool true = 1;
+    my_bool my_true = 1;
     VALUE st_obj;
 
     if ((s = mysql_stmt_init(m)) == NULL)
 	mysql_raise(m);
-    if (mysql_stmt_attr_set(s, STMT_ATTR_UPDATE_MAX_LENGTH, &true))
+    if (mysql_stmt_attr_set(s, STMT_ATTR_UPDATE_MAX_LENGTH, &my_true))
 	rb_raise(rb_eArgError, "mysql_stmt_attr_set() failed");
     st_obj = Data_Make_Struct(cMysqlStmt, struct mysql_stmt, 0, free_mysqlstmt, stmt);
     memset(stmt, 0, sizeof(*stmt));
@@ -1317,7 +1317,11 @@ static VALUE stmt_bind_result(int argc, 
 	}
 	else if (argv[i] == rb_cString)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_STRING;
-	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger || argv[i] == rb_cFixnum)
+	else if (argv[i] == rb_cNumeric || argv[i] == rb_cInteger
+#if RUBY_API_VERSION_MAJOR >=2 && RUBY_API_VERSION_MINOR < 4
+		 || argv[i] == rb_cFixnum
+#endif
+		)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_LONGLONG;
 	else if (argv[i] == rb_cFloat)
 	    s->result.bind[i].buffer_type = MYSQL_TYPE_DOUBLE;

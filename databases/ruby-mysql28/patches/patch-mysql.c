$NetBSD: patch-mysql.c,v 1.1 2017/10/13 16:07:51 taca Exp $

* Fix build with ruby24.

--- mysql.c.orig	2010-02-11 10:42:54.000000000 +0000
+++ mysql.c
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

$NetBSD: patch-sql_sql__prepare.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_prepare.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_prepare.cc
@@ -978,7 +978,7 @@ static bool setup_conversion_functions(P
 
       typecode= sint2korr(read_pos);
       read_pos+= 2;
-      (**it).unsigned_flag= test(typecode & signed_bit);
+      (**it).unsigned_flag= my_test(typecode & signed_bit);
       setup_one_conversion_function(thd, *it, (uchar) (typecode & ~signed_bit));
     }
   }
@@ -2653,7 +2653,7 @@ void mysqld_stmt_execute(THD *thd, char 
   DBUG_PRINT("exec_query", ("%s", stmt->query()));
   DBUG_PRINT("info",("stmt: 0x%lx", (long) stmt));
 
-  open_cursor= test(flags & (ulong) CURSOR_TYPE_READ_ONLY);
+  open_cursor= my_test(flags & (ulong) CURSOR_TYPE_READ_ONLY);
 
   thd->protocol= &thd->protocol_binary;
   stmt->execute_loop(&expanded_query, open_cursor, packet, packet_end);

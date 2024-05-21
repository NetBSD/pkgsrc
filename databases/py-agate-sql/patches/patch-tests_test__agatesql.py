$NetBSD: patch-tests_test__agatesql.py,v 1.1 2024/05/21 13:15:24 cheusov Exp $

Cratedb python module is not a part of pkgsrc.
That's why one test is disabled.

--- tests/test_agatesql.py.orig	2024-01-09 23:17:02.000000000 +0000
+++ tests/test_agatesql.py
@@ -166,7 +166,7 @@ class TestSQL(agate.AgateTestCase):
         self.assertEqual(statement.replace('\t', '  '), dedent(expected))
 
     def test_to_sql_create_statement_with_dialects(self):
-        for dialect in ['crate', 'mssql', 'mysql', 'postgresql', 'sqlite']:
+        for dialect in ['mssql', 'mysql', 'postgresql', 'sqlite']:
             self.table.to_sql_create_statement('test_table', dialect=dialect)
 
     def test_to_sql_create_statement_zero_width(self):

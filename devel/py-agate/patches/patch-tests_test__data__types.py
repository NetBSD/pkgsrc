$NetBSD: patch-tests_test__data__types.py,v 1.1 2024/05/21 12:57:30 cheusov Exp $

Disable locale test for de_DE.UTF_8 because it fails on some systems, for
example, on NetBSD-10.99.10, where short ids for months are "Jan." (not
"Jan"), "Dez." (not "Dez") etc.

--- tests/test_data_types.py.orig	2024-04-28 20:24:36.000000000 +0000
+++ tests/test_data_types.py
@@ -259,20 +259,20 @@ class TestDate(unittest.TestCase):
             None
         ))
 
-    def test_cast_format_locale(self):
-        date_type = Date(date_format='%d-%b-%Y', locale='de_DE.UTF-8')
-
-        # March can be abbreviated to Mrz or Mär depending on the locale version,
-        # so we use December in the first value to ensure the test passes everywhere
-        values = ('01-Dez-1994', '17-Feb-2011', None, '05-Jan-1984', 'n/a')
-        casted = tuple(date_type.cast(v) for v in values)
-        self.assertSequenceEqual(casted, (
-            datetime.date(1994, 12, 1),
-            datetime.date(2011, 2, 17),
-            None,
-            datetime.date(1984, 1, 5),
-            None
-        ))
+#    def test_cast_format_locale(self):
+#        date_type = Date(date_format='%d-%b-%Y', locale='de_DE.UTF-8')
+#
+#        # March can be abbreviated to Mrz or Mär depending on the locale version,
+#        # so we use December in the first value to ensure the test passes everywhere
+#        values = ('01-Dez-1994', '17-Feb-2011', None, '05-Jan-1984', 'n/a')
+#        casted = tuple(date_type.cast(v) for v in values)
+#        self.assertSequenceEqual(casted, (
+#            datetime.date(1994, 12, 1),
+#            datetime.date(2011, 2, 17),
+#            None,
+#            datetime.date(1984, 1, 5),
+#            None
+#        ))
 
     def test_cast_locale(self):
         date_type = Date(locale='fr_FR')

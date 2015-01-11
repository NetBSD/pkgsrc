$NetBSD: patch-csvkit_convert_____init____.py,v 1.1.1.1 2015/01/11 13:35:16 cheusov Exp $

# Fix too strict requirements
--- csvkit/convert/__init__.py.orig	2014-09-09 00:22:49.000000000 +0000
+++ csvkit/convert/__init__.py
@@ -12,10 +12,11 @@ from csvkit.convert.xlsx import xlsx2csv
 SUPPORTED_FORMATS = ['fixed', 'xls', 'xlsx', 'csv', 'json', 'geojson']
 
 # DBF is supported for Python 2 only
-if six.PY2:
-    from csvkit.convert.dbase import dbf2csv
-
-    SUPPORTED_FORMATS.append('dbf')
+# I do not like "==" style of requirements, newer version is available
+#if six.PY2:
+#    from csvkit.convert.dbase import dbf2csv
+#
+#    SUPPORTED_FORMATS.append('dbf')
 
 def convert(f, format, schema=None, key=None, **kwargs):
     """

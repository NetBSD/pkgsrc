$NetBSD: patch-csvkit_convert_xlsx.py,v 1.1 2021/11/24 10:22:32 wiz Exp $

use_iterators was replaced with read_only
https://openpyxl.readthedocs.io/en/stable/changes.html?highlight=use_iterators#a1-2016-04-11

--- csvkit/convert/xlsx.py.orig	2014-09-09 00:22:49.000000000 +0000
+++ csvkit/convert/xlsx.py
@@ -48,7 +48,7 @@ def xlsx2csv(f, output=None, **kwargs):
 
     writer = CSVKitWriter(output)
 
-    book = load_workbook(f, use_iterators=True, data_only=True)
+    book = load_workbook(f, read_only=True, data_only=True)
 
     if 'sheet' in kwargs:
         sheet = book.get_sheet_by_name(kwargs['sheet'])

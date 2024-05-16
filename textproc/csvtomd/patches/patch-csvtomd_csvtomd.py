$NetBSD: patch-csvtomd_csvtomd.py,v 1.1 2024/05/16 17:06:25 cheusov Exp $

We support only python3

--- csvtomd/csvtomd.py.orig	2016-12-18 21:43:02.000000000 +0000
+++ csvtomd/csvtomd.py
@@ -132,7 +132,7 @@ def main():
         else:
             first = False
         # Read the CSV files
-        with open(filename, 'rU') as f:
+        with open(filename, 'r') as f:
             table = csv_to_table(f, args.delimiter)
         # Print filename for each table if --no-filenames wasn't passed and
         # more than one CSV was provided

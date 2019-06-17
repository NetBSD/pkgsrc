$NetBSD: patch-ggplot_utils.py,v 1.1 2019/06/17 20:27:16 adam Exp $

Fix for newer Pandas.

--- ggplot/utils.py.orig	2019-06-17 20:04:20.000000000 +0000
+++ ggplot/utils.py
@@ -78,7 +78,7 @@ def is_iterable(obj):
         return False
 
 date_types = (
-    pd.tslib.Timestamp,
+    pd.Timestamp,
     pd.DatetimeIndex,
     pd.Period,
     pd.PeriodIndex,

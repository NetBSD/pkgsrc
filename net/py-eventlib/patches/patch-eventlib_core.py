$NetBSD: patch-eventlib_core.py,v 1.1 2014/06/06 12:49:23 joerg Exp $

--- eventlib/core.py.orig	2014-06-06 11:58:21.000000000 +0000
+++ eventlib/core.py
@@ -191,7 +191,7 @@ def filter_data_values(data):
     and return another dict without them.
     """
     banned = ('request',)
-    return {key: val for key, val in data.items() if not key in banned}
+    return dict((key, val) for key, val in data.items() if not key in banned)
 
 
 def import_event_modules():

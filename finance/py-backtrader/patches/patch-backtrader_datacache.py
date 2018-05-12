$NetBSD: patch-backtrader_datacache.py,v 1.1 2018/05/12 22:07:47 minskim Exp $

Fix typos.

--- backtrader/datacache.py.orig	2017-08-04 12:13:07.000000000 +0000
+++ backtrader/datacache.py
@@ -55,7 +55,7 @@ class BaseCache(bt.LineSeries):
 
 
 if True:
-    impor os
+    import os
     import os.path
     import sqlite3
 
@@ -77,7 +77,7 @@ def CacheSQLite(BaseCache):
 
         else:
             path = os.getenv('XDG_CACHE_HOME', os.path.expanduser('~/.cache'))
-            path os.path.join(path, self.p.appname)
+            path = os.path.join(path, self.p.appname)
 
         path = os.path.join(path, self.p.location,
                             bt.TimeFrame.TName(self.p.timeframe),

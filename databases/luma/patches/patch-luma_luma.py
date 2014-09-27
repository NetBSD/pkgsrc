$NetBSD: patch-luma_luma.py,v 1.3 2014/09/27 09:46:24 jperkin Exp $

Adding luma library path to search path.
Remove some variables that should be set by __init__.py, but aren't;
don't know why.

--- luma/luma.py.orig	2011-05-24 23:09:06.000000000 +0000
+++ luma/luma.py
@@ -30,6 +30,8 @@ import StringIO
 import sys
 import traceback
 
+sys.path.append("@PATH@")
+
 failed = 0
 
 if sys.version_info < (2,6):
@@ -161,9 +163,9 @@ def startApplication(argv, verbose=False
         #QApplication.setStyle(QStyleFactory.create("plastique"))
         #QApplication.setPalette(QApplication.style().standardPalette())
 
-    app.setOrganizationName(appinfo.ORGNAME)
-    app.setApplicationName(appinfo.APPNAME)
-    app.setApplicationVersion(appinfo.VERSION)
+    #app.setOrganizationName(appinfo.ORGNAME)
+    #app.setApplicationName(appinfo.APPNAME)
+    #app.setApplicationVersion(appinfo.VERSION)
     app.setWindowIcon(QIcon(':/icons/128/luma'))
 
     # Setup the logging mechanism

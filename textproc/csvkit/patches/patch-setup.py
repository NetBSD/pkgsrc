$NetBSD: patch-setup.py,v 1.2 2015/04/18 18:27:16 cheusov Exp $

# Fix too strict requirements
--- setup.py.orig	2014-09-09 00:22:49.000000000 +0000
+++ setup.py
@@ -8,7 +8,7 @@ install_requires = [
     'sqlalchemy>=0.6.6',
     'openpyxl>=2.0.3',
     'six>=1.6.1',
-    'python-dateutil==2.2'
+    'python-dateutil>=2.2'
 ]
 
 if sys.version_info < (2, 7):
@@ -16,8 +16,9 @@ if sys.version_info < (2, 7):
     install_requires.append('ordereddict>=1.1')
     install_requires.append('simplejson>=3.6.3')
 
-if sys.version_info[0] == 2:
-    install_requires.append('dbf==0.94.003')
+# I don't like "==" style of requirements, newer version is available
+#if sys.version_info[0] == 2:
+#    install_requires.append('dbf==0.94.003')
 
 setup(
     name='csvkit',

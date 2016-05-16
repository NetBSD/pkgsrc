$NetBSD: patch-setup.py,v 1.1 2016/05/16 15:05:48 nils Exp $

Fix build with python-3.x and C locale.
https://github.com/audreyr/cookiecutter/pull/639

--- setup.py.orig	2015-11-10 22:47:32.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 
 import os
+import io
 import sys
 
 try:
@@ -20,10 +21,10 @@ if sys.argv[-1] == 'tag':
     os.system("git push --tags")
     sys.exit()
 
-with open('README.rst') as readme_file:
+with io.open('README.rst', 'r', encoding='utf-8') as readme_file:
     readme = readme_file.read()
 
-with open('HISTORY.rst') as history_file:
+with io.open('HISTORY.rst', 'r', encoding='utf-8') as history_file:
     history = history_file.read().replace('.. :changelog:', '')
 
 requirements = [

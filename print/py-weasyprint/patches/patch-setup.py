$NetBSD: patch-setup.py,v 1.1 2015/08/14 17:05:04 kleink Exp $

Adjust script path to allow multiple Python version installs.

--- setup.py.orig	2014-05-05 12:33:27.000000000 +0200
+++ setup.py	2015-07-16 19:14:03.000000000 +0200
@@ -75,7 +75,7 @@
     test_suite='weasyprint.tests',
     entry_points={
         'console_scripts': [
-            'weasyprint = weasyprint.__main__:main',
+            'weasyprint%s = weasyprint.__main__:main' % sys.version[0:3],
         ],
     },
 )

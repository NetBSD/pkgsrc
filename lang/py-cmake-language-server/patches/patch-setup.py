$NetBSD: patch-setup.py,v 1.1 2020/05/18 15:19:01 wiz Exp $

Don't hardcode version numbers.

--- setup.py.orig	2020-03-01 07:51:19.388557700 +0000
+++ setup.py
@@ -11,7 +11,7 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['pygls>=0.8.1,<0.9.0', 'pyparsing>=2.4,<3.0']
+['pygls', 'pyparsing']
 
 entry_points = \
 {'console_scripts': ['cmake-format = cmake_language_server.formatter:main',

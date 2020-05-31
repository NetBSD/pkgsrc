$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:50:18 joerg Exp $

--- setup.py.orig	2020-05-31 18:04:01.913694430 +0000
+++ setup.py
@@ -9,7 +9,7 @@ from setuptools import setup, find_packa
 from setuptools.command.test import test as TestCommand
 
 here = os.path.abspath(os.path.dirname(__file__))
-README = open(os.path.join(here, 'README.md')).read()
+README = open(os.path.join(here, 'README.md'), **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read()
 CHANGES = open(os.path.join(here, 'CHANGES.rst')).read()
 
 

$NetBSD: patch-setup.py,v 1.1 2017/04/04 14:19:58 wiz Exp $

mando-0.5 is fine.
https://github.com/rubik/radon/issues/112

--- setup.py.orig	2016-11-02 12:22:42.000000000 +0000
+++ setup.py
@@ -19,8 +19,8 @@ setup(name='radon',
       packages=find_packages(),
       tests_require=['tox'],
       install_requires=[
-          'mando>=0.3,<0.4',
-          'colorama>=0.3,<0.4',
+          'mando',
+          'colorama',
           'flake8-polyfill',
       ],
       entry_points={

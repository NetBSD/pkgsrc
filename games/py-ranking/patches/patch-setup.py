$NetBSD: patch-setup.py,v 1.1 2021/12/17 00:23:00 wiz Exp $

Compatibility with setuptools.

--- setup.py.orig	2020-10-09 20:06:44.000000000 +0000
+++ setup.py
@@ -84,5 +84,4 @@ setup(
                  'Topic :: Games/Entertainment'],
     test_suite='rankingtests',
     tests_require=['pytest'],
-    use_2to3=(sys.version_info[0] >= 3),
 )

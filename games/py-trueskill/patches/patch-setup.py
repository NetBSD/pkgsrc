$NetBSD: patch-setup.py,v 1.1 2021/12/17 00:29:35 wiz Exp $

Compatibility with setuptools.

--- setup.py.orig	2014-09-04 04:44:36.000000000 +0000
+++ setup.py
@@ -97,5 +97,4 @@ setup(
                  'Topic :: Scientific/Engineering :: Mathematics'],
     tests_require=['pytest', 'almost>=0.1.5', 'mpmath>=0.17'],
     test_suite='trueskilltest',
-    use_2to3=(sys.version_info[0] >= 3),
 )

$NetBSD: patch-setup.py,v 1.1 2018/10/28 15:17:47 taca Exp $

Python 3.7 support from 0db68de5a45475b9af37b8c3dade560c2d5317cd.

--- setup.py.orig	2017-11-07 17:46:36.000000000 +0000
+++ setup.py
@@ -108,6 +108,7 @@ setup(name='zope.hookable',
           "Programming Language :: Python :: 3.4",
           "Programming Language :: Python :: 3.5",
           "Programming Language :: Python :: 3.6",
+          "Programming Language :: Python :: 3.7",
           "Programming Language :: Python :: Implementation :: CPython",
           "Programming Language :: Python :: Implementation :: PyPy",
           "Framework :: Zope3",
@@ -119,7 +120,7 @@ setup(name='zope.hookable',
       },
       packages=find_packages('src'),
       package_dir={'': 'src'},
-      namespace_packages=['zope',],
+      namespace_packages=['zope'],
       install_requires=[
           'setuptools',
       ],
@@ -128,7 +129,7 @@ setup(name='zope.hookable',
       test_suite='zope.hookable.tests.test_hookable.test_suite',
       extras_require={
           'docs': ['Sphinx'],
-          'testing': TESTS_REQUIRE + ['coverage',],
+          'testing': TESTS_REQUIRE + ['coverage'],
           'test': TESTS_REQUIRE,
       },
       python_requires='>=2.7,!=3.0.*,!=3.1.*,!=3.2.*,!=3.3.*',

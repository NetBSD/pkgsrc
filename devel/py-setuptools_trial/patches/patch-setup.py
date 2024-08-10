$NetBSD: patch-setup.py,v 1.2 2024/08/10 15:14:37 wiz Exp $

Test-runner is not really used.
https://github.com/rutsky/setuptools-trial/issues/272

Do not install docs and avoid conflict between Python versions.

--- setup.py.orig	2016-03-21 03:17:06.000000000 +0000
+++ setup.py
@@ -54,9 +54,6 @@ PKG = 'setuptools_trial'
 doc_loc = "share/doc/python-" + PKG
 data_files = [(doc_loc, data_fnames)]
 
-if {'pytest', 'test'}.intersection(sys.argv):
-    setup_requires.append('pytest_runner')
-
 setup(
     name=PKG,
     version=verstr,
@@ -86,7 +83,6 @@ setup(
     license="BSD",
     packages=find_packages(exclude=("tests",)),
     include_package_data=True,
-    data_files=data_files,
     classifiers=trove_classifiers,
     extras_require={
         ":python_version == '2.7'": ["pathlib2"],

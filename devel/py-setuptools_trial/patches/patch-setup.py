$NetBSD: patch-setup.py,v 1.1 2018/04/03 20:19:47 adam Exp $

Do not install docs and avoid conflict between Python versions.

--- setup.py.orig	2018-04-03 20:08:51.000000000 +0000
+++ setup.py
@@ -86,7 +86,6 @@ setup(
     license="BSD",
     packages=find_packages(exclude=("tests",)),
     include_package_data=True,
-    data_files=data_files,
     classifiers=trove_classifiers,
     extras_require={
         ":python_version == '2.7'": ["pathlib2"],

$NetBSD: patch-setup.py,v 1.3 2019/09/25 07:25:24 adam Exp $

Skip examples, as they make a conflict between Python versions.

--- setup.py.orig	2019-04-09 06:14:52.000000000 +0000
+++ setup.py
@@ -155,7 +155,6 @@ if __name__ == "__main__":
         project_urls=release.project_urls,
         classifiers=release.classifiers,
         packages=packages,
-        data_files=data,
         package_data=package_data,
         install_requires=install_requires,
         extras_require=extras_require,

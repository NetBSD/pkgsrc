$NetBSD: patch-setup.py,v 1.4 2023/05/09 08:26:44 adam Exp $

Skip examples, as they make a conflict between Python versions.

--- setup.py.orig	2023-03-29 17:31:10.000000000 +0000
+++ setup.py
@@ -189,7 +189,6 @@ if __name__ == "__main__":
         project_urls=project_urls,
         classifiers=classifiers,
         packages=packages,
-        data_files=data,
         package_data=package_data,
         install_requires=install_requires,
         extras_require=extras_require,

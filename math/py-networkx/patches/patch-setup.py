$NetBSD: patch-setup.py,v 1.1 2018/11/30 10:37:07 adam Exp $

Do not install examples; they have different requirements.

--- setup.py.orig	2018-11-30 10:28:52.000000000 +0000
+++ setup.py
@@ -150,7 +150,6 @@ if __name__ == "__main__":
         download_url=release.download_url,
         classifiers=release.classifiers,
         packages=packages,
-        data_files=data,
         package_data=package_data,
         install_requires=install_requires,
         extras_require=extras_require,

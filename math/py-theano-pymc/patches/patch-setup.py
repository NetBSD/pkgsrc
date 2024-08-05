$NetBSD: patch-setup.py,v 1.1 2024/08/05 19:32:15 adam Exp $

Properly exclude tests.

--- setup.py.orig	2024-08-05 19:07:38.882824553 +0000
+++ setup.py
@@ -56,7 +56,7 @@ if __name__ == "__main__":
         url=URL,
         license=LICENSE,
         platforms=PLATFORMS,
-        packages=find_packages(exclude=["tests.*"]),
+        packages=find_packages(exclude=["tests*"]),
         install_requires=["numpy>=1.9.1", "scipy>=0.14", "filelock"],
         package_data={
             "": [

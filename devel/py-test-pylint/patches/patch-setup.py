$NetBSD: patch-setup.py,v 1.1 2024/08/10 15:18:02 wiz Exp $

https://github.com/carsongee/pytest-pylint/issues/195

--- setup.py.orig	2024-08-10 15:16:46.983772565 +0000
+++ setup.py
@@ -28,7 +28,7 @@ setup(
         "pylint>=2.15.0",
         "tomli>=1.1.0; python_version < '3.11'",
     ],
-    setup_requires=["pytest-runner"],
+    setup_requires=[],
     tests_require=["coverage", "flake8", "black", "isort"],
     classifiers=[
         "Development Status :: 5 - Production/Stable",

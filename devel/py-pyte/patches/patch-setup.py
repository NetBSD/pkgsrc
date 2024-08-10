$NetBSD: patch-setup.py,v 1.1 2024/08/10 15:05:08 wiz Exp $

https://github.com/selectel/pyte/issues/176

--- setup.py.orig	2024-08-10 15:03:06.078284940 +0000
+++ setup.py
@@ -37,7 +37,7 @@ setup(name="pyte",
       version="0.8.2",
       packages=["pyte"],
       install_requires=["wcwidth"],
-      setup_requires=["pytest-runner"],
+      setup_requires=[],
       tests_require=["pytest"],
       python_requires=">=3.8",
       platforms=["any"],

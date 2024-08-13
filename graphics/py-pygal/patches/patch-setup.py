$NetBSD: patch-setup.py,v 1.2 2024/08/13 08:27:27 adam Exp $

https://github.com/Kozea/pygal/issues/430

--- setup.py.orig	2024-08-12 14:53:53.000000000 +0000
+++ setup.py
@@ -62,7 +62,7 @@ setup(
     scripts=["pygal_gen.py"],
     keywords=[
         "svg", "chart", "graph", "diagram", "plot", "histogram", "kiviat"],
-    setup_requires=['pytest-runner'],
+    setup_requires=[],
     install_requires=['importlib-metadata'],  # TODO: remove this (see #545, #546)
     package_data={'pygal': ['css/*', 'graph/maps/*.svg']},
     extras_require={

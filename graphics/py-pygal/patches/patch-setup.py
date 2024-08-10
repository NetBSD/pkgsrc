$NetBSD: patch-setup.py,v 1.1 2024/08/10 15:46:27 wiz Exp $

https://github.com/Kozea/pygal/issues/430

--- setup.py.orig	2024-08-10 15:35:48.260480748 +0000
+++ setup.py
@@ -44,7 +44,7 @@ tests_requirements = [
     "pyquery", "flask", 'cairosvg', 'lxml', 'pygal_maps_world', 'pygal_maps_fr',
     'pygal_maps_ch', 'coveralls',
     'flake8',
-    'pytest-runner', 'pytest-cov', 'pytest-isort',
+    'pytest-cov', 'pytest-isort',
     'pytest'
 ]
 
@@ -70,7 +70,7 @@ setup(
     scripts=["pygal_gen.py"],
     keywords=[
         "svg", "chart", "graph", "diagram", "plot", "histogram", "kiviat"],
-    setup_requires=['pytest-runner'],
+    setup_requires=[],
     install_requires=['importlib-metadata'],  # TODO: remove this (see #545, #546)
     cmdclass={'test': PyTest},
     package_data={'pygal': ['css/*', 'graph/maps/*.svg']},

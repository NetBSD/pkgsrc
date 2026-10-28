$NetBSD: patch-kivy_tests_conftest.py,v 1.1 2026/10/28 05:09:43 wiz Exp $

https://github.com/kivy/kivy/commit/122596b656304aef81b53de2aebfc53bd24f0ecc

--- kivy/tests/conftest.py.orig	2026-10-28 04:29:19.784222810 +0000
+++ kivy/tests/conftest.py
@@ -6,7 +6,7 @@ try:
 try:
     from .fixtures import kivy_app, kivy_clock, kivy_metrics, \
         kivy_exception_manager
-except SyntaxError:
+except (SyntaxError, ImportError):
     # async app tests would be skipped due to async_run forcing it to skip so
     # it's ok to fail here as it won't be used anyway
     pass

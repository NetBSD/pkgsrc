$NetBSD: patch-kivy_tests_common.py,v 1.1 2026/10/28 05:09:43 wiz Exp $

https://github.com/kivy/kivy/commit/122596b656304aef81b53de2aebfc53bd24f0ecc

--- kivy/tests/common.py.orig	2026-10-28 04:29:19.784039385 +0000
+++ kivy/tests/common.py
@@ -498,7 +498,10 @@ def async_run(func=None, app_cls_func=None):
         if kivy_eventloop == 'asyncio':
             try:
                 import pytest_asyncio
-                return pytest.mark.asyncio(pytest_asyncio.fixture(func))
+                # In pytest 9, marks on fixtures have no effect.
+                # We only need to mark the async test function,
+                # not turn it into a fixture.
+                return pytest.mark.asyncio(func)
             except ImportError:
                 return pytest.mark.skip(
                     reason='KIVY_EVENTLOOP == "asyncio" but '

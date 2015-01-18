$NetBSD: patch-setuptools_tests_test__easy__install.py,v 1.1 2015/01/18 17:29:01 wiz Exp $

Fix comment -- this is not an interpreter.

--- setuptools/tests/test_easy_install.py.orig	2015-01-16 22:16:09.000000000 +0000
+++ setuptools/tests/test_easy_install.py
@@ -1,4 +1,4 @@
-#! -*- coding: utf-8 -*-
+# -*- coding: utf-8 -*-
 
 """Easy install Tests
 """

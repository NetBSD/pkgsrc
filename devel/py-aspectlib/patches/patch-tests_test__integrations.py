$NetBSD: patch-tests_test__integrations.py,v 1.1 2026/11/09 09:29:29 wiz Exp $

Add NetBSD errno for ECONNREFUSED.
https://github.com/ionelmc/python-aspectlib/issues/31

--- tests/test_integrations.py.orig	2022-10-20 15:54:11.000000000 +0000
+++ tests/test_integrations.py
@@ -23,7 +23,7 @@ LOG_TEST_SOCKET = r"""^\{_?socket(object)?\}.connect\(
     from io import StringIO
 
 LOG_TEST_SOCKET = r"""^\{_?socket(object)?\}.connect\(\('127.0.0.1', 1\)\) +<<< .*tests[\/]test_integrations.py:\d+:test_socket.*
-\{_?socket(object)?\}.connect \~ raised .*(ConnectionRefusedError|error)\((10061|111), .*refused.*\)"""
+\{_?socket(object)?\}.connect \~ raised .*(ConnectionRefusedError|error)\((10061|111|61), .*refused.*\)"""
 
 
 def test_mock_builtin():

$NetBSD: patch-testing_cffi1_test__verify1.py,v 1.1 2023/11/05 13:36:15 wiz Exp $

Add NetBSD support.

--- testing/cffi1/test_verify1.py.orig	2017-07-03 17:44:21.313824096 +0000
+++ testing/cffi1/test_verify1.py
@@ -1767,7 +1767,7 @@ def test_callback_indirection():
         #include <malloc.h>
         #define alloca _alloca
         #else
-        # ifdef __FreeBSD__
+        # if defined(__FreeBSD__) || defined(__NetBSD__)
         #  include <stdlib.h>
         # else
         #  include <alloca.h>

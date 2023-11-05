$NetBSD: patch-testing_cffi0_test__verify.py,v 1.1 2023/11/05 13:36:15 wiz Exp $

Add NetBSD support.

--- testing/cffi0/test_verify.py.orig	2017-07-03 17:44:02.180970759 +0000
+++ testing/cffi0/test_verify.py
@@ -1798,7 +1798,7 @@ def test_callback_indirection():
         #include <malloc.h>
         #define alloca _alloca
         #else
-        # ifdef __FreeBSD__
+        # if defined(__FreeBSD__) || defined(__NetBSD__)
         #  include <stdlib.h>
         # else
         #  include <alloca.h>

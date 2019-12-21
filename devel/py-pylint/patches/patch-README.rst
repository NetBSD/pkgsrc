$NetBSD: patch-README.rst,v 1.1 2019/12/21 23:36:23 joerg Exp $

Remove non-ASCII character.

--- README.rst.orig	2019-12-21 21:20:53.977120638 +0000
+++ README.rst
@@ -126,7 +126,7 @@ We use pytest_ for testing ``pylint``, w
 
 If you want to run tests on a specific portion of the code with pytest_, (pytest-cov_) and your local python version::
 
-    # ( pip install pytest-cov )
+    # ( pip install pytest-cov )
     # Everything:
     python3 -m pytest tests/
     # Everything in tests/message with coverage for the relevant code:

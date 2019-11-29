$NetBSD: patch-README.rst,v 1.1 2019/11/29 09:46:36 adam Exp $

Trim non-ASCII characters.

--- README.rst.orig	2019-11-29 09:37:57.000000000 +0000
+++ README.rst
@@ -237,14 +237,14 @@ __ https://travis-ci.org/wolever/paramet
      - no**
      - no**
    * - py.test fixtures
-     - no†
-     - no†
-     - no†
-     - no†
-     - no†
-     - no†
-     - no†
-     - no†
+     - no
+     - no
+     - no
+     - no
+     - no
+     - no
+     - no
+     - no
    * - | unittest
        | (``@parameterized.expand``)
      - yes
@@ -270,7 +270,7 @@ __ https://travis-ci.org/wolever/paramet
 
 \*\*: py.test 4 is not yet supported (but coming!) in `issue #34`__
 
-†: py.test fixture support is documented in `issue #81`__
+: py.test fixture support is documented in `issue #81`__
 
 __ https://github.com/wolever/parameterized/issues/71
 __ https://github.com/wolever/parameterized/issues/34

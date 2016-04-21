$NetBSD: patch-lib_equations-parser.vala,v 1.1 2016/04/21 22:11:32 prlw1 Exp $

equation: fix precedence of the root operator with regards to the unary minus
commit 87f716da

--- ./lib/equation-parser.vala.orig	2016-02-15 16:53:44.000000000 +0000
+++ ./lib/equation-parser.vala
@@ -26,15 +26,15 @@ private enum Precedence
     MOD             = 3,
     DIVIDE          = 3,
     NOT             = 4,
-    ROOT            = 5,
-    FUNCTION        = 6,
-    BOOLEAN         = 7,
-    PERCENTAGE      = 8,
-    /* UNARY_MINUS and POWER must have same precedence. */
-    UNARY_MINUS     = 9,
-    POWER           = 9,
-    FACTORIAL       = 10,
-    NUMBER_VARIABLE = 11,
+    FUNCTION        = 5,
+    BOOLEAN         = 6,
+    PERCENTAGE      = 7,
+    /* UNARY_MINUS, ROOT and POWER must have same precedence. */
+    UNARY_MINUS     = 8,
+    POWER           = 8,
+    ROOT            = 8,
+    FACTORIAL       = 9,
+    NUMBER_VARIABLE = 10,
     /* DEPTH should be always at the bottom. It stops node jumping off the current depth level. */
     DEPTH
 }

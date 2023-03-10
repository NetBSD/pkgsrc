$NetBSD: patch-renpy_sl2_slast.py,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* Fix compile with Python 3.11.
  From: https://github.com/renpy/renpy/commit/ccb075ea538b21d3ca2a21d2f04cd5de170789bc

--- renpy/sl2/slast.py.orig	2022-09-08 03:49:02.967533000 +0000
+++ renpy/sl2/slast.py
@@ -80,10 +80,9 @@ def compile_expr(loc, node):
         flags = renpy.python.new_compile_flags
 
     expr = ast.Expression(body=node)
-    ast.fix_missing_locations(expr)
+    renpy.python.fix_locations(expr, 1, 0)
     return compile(expr, filename, "eval", flags, 1)
 
-
 class SLContext(renpy.ui.Addable):
     """
     A context object that can be passed to the execute methods, and can also

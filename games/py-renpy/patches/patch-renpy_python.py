$NetBSD: patch-renpy_python.py,v 1.1 2023/03/10 21:14:39 ryoon Exp $

* Fix compile with Python 3.11.
  From: https://github.com/renpy/renpy/commit/ccb075ea538b21d3ca2a21d2f04cd5de170789bc

--- renpy/python.py.orig	2022-09-08 03:49:02.963533200 +0000
+++ renpy/python.py
@@ -776,20 +776,32 @@ py_compile_cache = { }
 old_py_compile_cache = { }
 
 
-# Duplicated from ast.py to prevent a gc cycle.
-def fix_missing_locations(node, lineno, col_offset):
-    if 'lineno' in node._attributes:
-        if not hasattr(node, 'lineno'):
-            node.lineno = lineno
-        else:
-            lineno = node.lineno
-    if 'col_offset' in node._attributes:
-        if not hasattr(node, 'col_offset'):
-            node.col_offset = col_offset
-        else:
-            col_offset = node.col_offset
+def fix_locations(node, lineno, col_offset):
+    """
+    Assigns locations to the given node, and all of its children, adding
+    any missing line numbers and column offsets.
+    """
+
+    start = max(
+        (lineno, col_offset),
+        (getattr(node, "lineno", None) or 1, getattr(node, "col_offset", None) or 0)
+    )
+
+    lineno, col_offset = start
+
+    node.lineno = lineno
+    node.col_offset = col_offset
+
+    ends = [ start, (getattr(node, "end_lineno", None) or 1, getattr(node, "end_col_offset", None) or 0) ]
+
     for child in ast.iter_child_nodes(node):
-        fix_missing_locations(child, lineno, col_offset)
+        fix_locations(child, lineno, col_offset)
+        ends.append((child.end_lineno, child.end_col_offset))
+
+    end = max(ends)
+
+    node.end_lineno = end[0]
+    node.end_col_offset = end[1]
 
 
 def quote_eval(s):
@@ -993,7 +1005,7 @@ def py_compile(source, mode, filename='<
         if mode == "hide":
             wrap_hide(tree)
 
-        fix_missing_locations(tree, 1, 0)
+        fix_locations(tree, 1, 0)
         ast.increment_lineno(tree, lineno - 1)
 
         line_offset = 0
@@ -1006,7 +1018,7 @@ def py_compile(source, mode, filename='<
         except SyntaxError as orig_e:
             try:
                 tree = renpy.compat.fixes.fix_ast(tree)
-                fix_missing_locations(tree, 1, 0)
+                fix_locations(tree, 1, 0)
                 rv = compile(tree, filename, py_mode, flags, 1)
             except:
                 raise orig_e

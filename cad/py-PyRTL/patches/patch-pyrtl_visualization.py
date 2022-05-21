$NetBSD: patch-pyrtl_visualization.py,v 1.2 2022/05/21 15:01:00 ryoon Exp $

* Support SVG output with py-graphviz 0.19 or later too.
  https://github.com/UCSBarchlab/PyRTL/pull/416/

--- pyrtl/visualization.py.orig	2021-09-02 19:11:31.000000000 +0000
+++ pyrtl/visualization.py
@@ -453,8 +453,16 @@ def block_to_svg(block=None, split_state
     """
     try:
         from graphviz import Source
-        return Source(block_to_graphviz_string(block, split_state=split_state,
-                                               maintain_arg_order=maintain_arg_order))._repr_svg_()
+        src = Source(block_to_graphviz_string(block, split_state=split_state,
+                                              maintain_arg_order=maintain_arg_order))
+        try:
+            svg = src._repr_image_svg_xml()
+        except AttributeError:
+            # py-graphviz 0.18.3 or earlier
+            return src._repr_svg_()
+        else:
+            # py-graphviz 0.19 or later
+            return svg
     except ImportError:
         raise PyrtlError('need graphviz installed (try "pip install graphviz")')
 

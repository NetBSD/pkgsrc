$NetBSD: patch-waftools_generators_headers.py,v 1.1 2014/10/12 16:00:30 wiz Exp $

waf-1.8.x compatibility.
https://github.com/mpv-player/mpv/commit/d906d091627a9be8d0d1e13f54d737eca6dc16ff

--- waftools/generators/headers.py.orig	2014-09-30 18:52:47.000000000 +0000
+++ waftools/generators/headers.py
@@ -1,5 +1,5 @@
 def __cp_to_variant__(ctx, variant, basename):
-    src = ctx.bldnode.search(basename).read()
+    src = ctx.bldnode.search_node(basename).read()
     node = ctx.bldnode.make_node("{0}/{1}".format(variant, basename))
     node.parent.mkdir()
     node.write(src)

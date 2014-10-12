$NetBSD: patch-waftools_waf__customizations.py,v 1.1 2014/10/12 16:00:30 wiz Exp $

waf-1.8.x compatibility
https://github.com/mpv-player/mpv/commit/d906d091627a9be8d0d1e13f54d737eca6dc16ff

--- waftools/waf_customizations.py.orig	2014-09-30 18:52:47.000000000 +0000
+++ waftools/waf_customizations.py
@@ -30,28 +30,14 @@ def m_hook(self, node):
 
 def build(ctx):
     from waflib import Task
-    import syms
+
+    def nice_path(node):
+        node.path_from(node.ctx.launch_node())
 
     cls = Task.classes['cprogram']
     class cprogram(cls):
         run_str = cls.hcode + '${LAST_LINKFLAGS}'
 
-        def __str__(self):
-            tgt_str = ' '.join([a.nice_path() for a in self.outputs])
-            return 'linking -> {0}\n'.format(tgt_str)
-
-    cls = Task.classes['cshlib']
-    class cshlib(cls):
-        def __str__(self):
-            tgt_str = ' '.join([a.nice_path() for a in self.outputs])
-            return 'linking -> {0}\n'.format(tgt_str)
-
-    cls = Task.classes['compile_sym']
-    class compile_sym(cls):
-        def __str__(self):
-            tgt_str = ' '.join([a.nice_path() for a in self.outputs])
-            return 'compile_sym -> {0}\n'.format(tgt_str)
-
     cls = Task.classes['macplist']
     class macplist(cls):
         def run(self):

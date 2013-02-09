$NetBSD: patch-build_generator_gen__make.py,v 1.1 2013/02/09 13:27:27 ryoon Exp $

--- build/generator/gen_make.py.orig	2009-02-04 21:18:44.000000000 +0000
+++ build/generator/gen_make.py
@@ -23,9 +23,9 @@ from gen_base import build_path_join, bu
 class Generator(gen_base.GeneratorBase):
 
   _extension_map = {
-    ('exe', 'target'): '$(EXEEXT)',
+    ('exe', 'target'): '16$(EXEEXT)',
     ('exe', 'object'): '.o',
-    ('lib', 'target'): '.la',
+    ('lib', 'target'): '16.la',
     ('lib', 'object'): '.lo',
     }
 
@@ -424,7 +424,7 @@ class Generator(gen_base.GeneratorBase):
     self.begin_section('The install-include rule')
 
     includedir = build_path_join('$(includedir)',
-                                 'subversion-%s' % self.version)
+                                 'subversion-%s16' % self.version)
     self.ofile.write('install-include: %s\n'
                      '\t$(MKDIR) $(DESTDIR)%s\n'
                      % (' '.join(self.includes), includedir))

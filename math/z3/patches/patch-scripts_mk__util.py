$NetBSD: patch-scripts_mk__util.py,v 1.2 2018/02/23 17:04:43 khorben Exp $

For pkgsrc, use site-packages rather than dist-packages.
Add support for DESTDIR.

diff -r 59247c69b92d scripts/mk_util.py
--- scripts/mk_util.py.orig	2018-02-22 23:06:23.490379838 +0000
+++ scripts/mk_util.py
@@ -637,7 +637,7 @@ def parse_options():
             SLOW_OPTIMIZE = True
         elif not IS_WINDOWS and opt in ('-p', '--prefix'):
             PREFIX = arg
-            PYTHON_PACKAGE_DIR = os.path.join(PREFIX, 'lib', 'python%s' % distutils.sysconfig.get_python_version(), 'dist-packages')
+            PYTHON_PACKAGE_DIR = os.path.join(PREFIX, 'lib', 'python%s' % distutils.sysconfig.get_python_version(), 'site-packages')
             mk_dir(DESTDIR + PYTHON_PACKAGE_DIR)
             if sys.version >= "3":
                 mk_dir(os.path.join(DESTDIR + PYTHON_PACKAGE_DIR, '__pycache__'))
@@ -1506,8 +1506,8 @@ class MLComponent(Component):
                         get_component(Z3_DLL_COMPONENT).dll_name + '$(SO_EXT)',
                         os.path.join(sub_dir, 'z3ml.cmxa'),
                         os.path.join(sub_dir, 'META')))
-                out.write('\t%s remove Z3\n' % (OCAMLFIND))
-                out.write('\t%s install Z3 %s' % (OCAMLFIND, (os.path.join(sub_dir, 'META'))))
+                out.write('\t%s remove -destdir $(DESTDIR)/ -ldconf ignore Z3\n' % (OCAMLFIND))
+                out.write('\t%s install -destdir $(DESTDIR)/ -ldconf ignore Z3 %s' % (OCAMLFIND, (os.path.join(sub_dir, 'META'))))
                 for m in modules:
                     out.write(' %s.cma' % (os.path.join(sub_dir, m)))
                     out.write(' %s.cmx' % (os.path.join(sub_dir, m)))

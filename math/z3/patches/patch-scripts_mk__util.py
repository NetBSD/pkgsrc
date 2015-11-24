$NetBSD: patch-scripts_mk__util.py,v 1.1 2015/11/24 05:45:58 dholland Exp $

For pkgsrc, use site-packages rather than dist-packages.

diff -r 59247c69b92d scripts/mk_util.py
--- scripts/mk_util.py	Mon Nov 23 19:08:36 2015 -0500
+++ scripts/mk_util.py	Mon Nov 23 19:50:45 2015 -0500
@@ -637,7 +637,7 @@
             SLOW_OPTIMIZE = True
         elif not IS_WINDOWS and opt in ('-p', '--prefix'):
             PREFIX = arg
-            PYTHON_PACKAGE_DIR = os.path.join(PREFIX, 'lib', 'python%s' % distutils.sysconfig.get_python_version(), 'dist-packages')
+            PYTHON_PACKAGE_DIR = os.path.join(PREFIX, 'lib', 'python%s' % distutils.sysconfig.get_python_version(), 'site-packages')
             mk_dir(DESTDIR + PYTHON_PACKAGE_DIR)
             if sys.version >= "3":
                 mk_dir(os.path.join(DESTDIR + PYTHON_PACKAGE_DIR, '__pycache__'))

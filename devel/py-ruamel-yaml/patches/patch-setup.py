$NetBSD: patch-setup.py,v 1.3 2022/01/10 22:40:19 wiz Exp $

Allow standard pkgsrc installation.

--- setup.py.orig	2021-12-25 06:50:42.000000000 +0000
+++ setup.py
@@ -326,13 +326,6 @@ class NameSpacePackager(object):
             debug('calling setup.py', sys.argv)
             if '-h' in sys.argv:
                 pass
-            elif '--single-version-externally-managed' not in sys.argv:
-                if os.environ.get('READTHEDOCS', None) == 'True':
-                    os.system('pip install .')
-                    sys.exit(0)
-                if not os.environ.get('RUAMEL_NO_PIP_INSTALL_CHECK', False):
-                    print('error: you have to install with "pip install ."')
-                    sys.exit(1)
         # If you only support an extension module on Linux, Windows thinks it
         # is pure. That way you would get pure python .whl files that take
         # precedence for downloading on Linux over source with compilable C code

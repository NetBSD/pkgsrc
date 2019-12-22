$NetBSD: patch-meld_build_helpers.py,v 1.1 2019/12/22 20:40:51 markd Exp $

commit 7862ee014ecb85b2a7fe409f8b147b1ddb6e657e
Update build helpers for Python 3.8 compatibility

--- meld/build_helpers.py.orig	2019-03-30 21:54:28.000000000 +0000
+++ meld/build_helpers.py
@@ -31,6 +31,15 @@ import platform
 import sys
 from distutils.log import info
 
+try:
+    import distro
+except ImportError:
+    python_version = tuple(int(x) for x in platform.python_version_tuple())
+    if python_version >= (3, 8):
+        print(
+            'Missing build requirement "distro" Python module; '
+            'install paths may be incorrect', file=sys.stderr)
+
 
 def has_help(self):
     return "build_help" in self.distribution.cmdclass and os.name != 'nt'
@@ -378,11 +387,21 @@ class install(distutils.command.install.
 
     def finalize_options(self):
         special_cases = ('debian', 'ubuntu', 'linuxmint')
-        if (platform.system() == 'Linux' and
-                platform.linux_distribution()[0].lower() in special_cases):
-            # Maintain an explicit install-layout, but use deb by default
-            specified_layout = getattr(self, 'install_layout', None)
-            self.install_layout = specified_layout or 'deb'
+        if platform.system() == 'Linux':
+            # linux_distribution has been removed in Python 3.8; we require
+            # the third-party distro package for future handling.
+            try:
+                distribution = platform.linux_distribution()[0].lower()
+            except AttributeError:
+                try:
+                    distribution = distro.id()
+                except NameError:
+                    distribution = 'unknown'
+
+            if distribution in special_cases:
+                # Maintain an explicit install-layout, but use deb by default
+                specified_layout = getattr(self, 'install_layout', None)
+                self.install_layout = specified_layout or 'deb'
 
         distutils.command.install.install.finalize_options(self)
 

$NetBSD: patch-magic_loader.py,v 1.1 2021/02/18 12:29:55 adam Exp $

NetBSD support.

--- magic/loader.py.orig	2021-02-18 12:24:08.000000000 +0000
+++ magic/loader.py
@@ -24,9 +24,15 @@ def load_lib():
                         'win32': windows_dlls,
                         'cygwin': windows_dlls,
                         'linux': ['libmagic.so.1'],
+                        'netbsd': ['libmagic.so.6.0'],
                         # fallback for some Linuxes (e.g. Alpine) where library search does not work # flake8:noqa
                         }
-      platform = 'linux' if sys.platform.startswith('linux') else sys.platform
+      if sys.platform.startswith('linux'):
+          platform = 'linux'
+      elif sys.platform.startswith('netbsd'):
+          platform = 'netbsd'
+      else:
+          sys.platform
       for dll in platform_to_lib.get(platform, []):
           try:
               libmagic = ctypes.CDLL(dll)

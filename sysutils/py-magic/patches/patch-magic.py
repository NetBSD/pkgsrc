$NetBSD: patch-magic.py,v 1.1 2020/10/04 18:15:43 js Exp $

--- magic.py.orig	2020-05-06 02:14:40.000000000 +0000
+++ magic.py
@@ -187,8 +187,10 @@ if not libmagic or not libmagic._name:
                        'win32': windows_dlls,
                        'cygwin': windows_dlls,
                        'linux': ['libmagic.so.1'],  # fallback for some Linuxes (e.g. Alpine) where library search does not work # flake8:noqa
+                       'netbsd': ['libmagic.so.6.0'],  # fallback for running in chroot
                       }
     platform = 'linux' if sys.platform.startswith('linux') else sys.platform
+    platform = 'netbsd' if sys.platform.startswith('netbsd') else sys.platform
     for dll in platform_to_lib.get(platform, []):
         try:
             libmagic = ctypes.CDLL(dll)

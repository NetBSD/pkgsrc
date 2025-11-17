$NetBSD: patch-SCons_Platform_____init____.py,v 1.2 2025/11/17 07:43:46 adam Exp $

Do not treat SunOS as non-posix, it causes massive breakage.

--- SCons/Platform/__init__.py.orig	2025-11-16 22:02:53.000000000 +0000
+++ SCons/Platform/__init__.py
@@ -76,8 +76,6 @@ def platform_default():
             return 'cygwin'
         elif 'irix' in sys.platform:
             return 'irix'
-        elif 'sunos' in sys.platform:
-            return 'sunos'
         elif 'hp-ux' in sys.platform:
             return 'hpux'
         elif 'aix' in sys.platform:

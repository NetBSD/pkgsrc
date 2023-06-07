$NetBSD: patch-SCons_Platform_____init____.py,v 1.1 2023/06/07 18:25:04 wiz Exp $

Do not treat SunOS as non-posix, it causes massive breakage.

--- SCons/Platform/__init__.py.orig	2023-01-24 04:14:53.000000000 +0000
+++ SCons/Platform/__init__.py
@@ -67,8 +67,6 @@ def platform_default():
             return 'cygwin'
         elif sys.platform.find('irix') != -1:
             return 'irix'
-        elif sys.platform.find('sunos') != -1:
-            return 'sunos'
         elif sys.platform.find('hp-ux') != -1:
             return 'hpux'
         elif sys.platform.find('aix') != -1:

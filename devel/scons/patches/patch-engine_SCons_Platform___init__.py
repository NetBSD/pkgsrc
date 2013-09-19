$NetBSD: patch-engine_SCons_Platform___init__.py,v 1.1 2013/09/19 11:07:04 jperkin Exp $

Do not treat SunOS as non-posix, it causes massive breakage.

--- engine/SCons/Platform/__init__.py.orig	2013-03-03 14:48:39.000000000 +0000
+++ engine/SCons/Platform/__init__.py
@@ -70,8 +70,8 @@ def platform_default():
             return 'cygwin'
         elif sys.platform.find('irix') != -1:
             return 'irix'
-        elif sys.platform.find('sunos') != -1:
-            return 'sunos'
+        #elif sys.platform.find('sunos') != -1:
+        #    return 'sunos'
         elif sys.platform.find('hp-ux') != -1:
             return 'hpux'
         elif sys.platform.find('aix') != -1:

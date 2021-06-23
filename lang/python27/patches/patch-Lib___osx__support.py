$NetBSD: patch-Lib___osx__support.py,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Lib/_osx_support.py.orig	2021-06-22 19:20:03.000000000 +0000
+++ Lib/_osx_support.py
@@ -470,6 +470,8 @@ def get_platform_osx(_config_vars, osnam
 
             if len(archs) == 1:
                 machine = archs[0]
+            elif archs == ('arm64', 'x86_64'):
+                machine = 'universal2'
             elif archs == ('i386', 'ppc'):
                 machine = 'fat'
             elif archs == ('i386', 'x86_64'):
@@ -484,6 +486,10 @@ def get_platform_osx(_config_vars, osnam
                 raise ValueError(
                    "Don't know machine value for archs=%r" % (archs,))
 
+        elif machine == 'arm':
+            # No 32-bit arm support on macOS
+            machine = 'arm64'
+
         elif machine == 'i386':
             # On OSX the machine type returned by uname is always the
             # 32-bit variant, even if the executable architecture is

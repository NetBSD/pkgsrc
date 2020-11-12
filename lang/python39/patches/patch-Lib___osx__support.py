$NetBSD: patch-Lib___osx__support.py,v 1.1 2020/11/12 10:58:21 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Backported from:
https://github.com/python/cpython/pull/22855

--- Lib/_osx_support.py.orig	2020-10-05 15:07:58.000000000 +0000
+++ Lib/_osx_support.py
@@ -110,6 +110,26 @@ def _get_system_version():
 
     return _SYSTEM_VERSION
 
+_SYSTEM_VERSION_TUPLE = None
+def _get_system_version_tuple():
+    """
+    Return the macOS system version as a tuple
+
+    The return value is safe to use to compare
+    two version numbers.
+    """
+    global _SYSTEM_VERSION_TUPLE
+    if _SYSTEM_VERSION_TUPLE is None:
+        osx_version = _get_system_version()
+        if osx_version:
+            try:
+                _SYSTEM_VERSION_TUPLE = tuple(int(i) for i in osx_version.split('.'))
+            except ValueError:
+                _SYSTEM_VERSION_TUPLE = ()
+
+    return _SYSTEM_VERSION_TUPLE
+   
+
 def _remove_original_values(_config_vars):
     """Remove original unmodified values for testing"""
     # This is needed for higher-level cross-platform tests of get_platform.
@@ -132,14 +152,18 @@ def _supports_universal_builds():
     # builds, in particular -isysroot and -arch arguments to the compiler. This
     # is in support of allowing 10.4 universal builds to run on 10.3.x systems.
 
-    osx_version = _get_system_version()
-    if osx_version:
-        try:
-            osx_version = tuple(int(i) for i in osx_version.split('.'))
-        except ValueError:
-            osx_version = ''
+    osx_version = _get_system_version_tuple()
     return bool(osx_version >= (10, 4)) if osx_version else False
 
+def _supports_arm64_builds():
+    """Returns True if arm64 builds are supported on this system"""
+    # There are two sets of systems supporting macOS/arm64 builds:
+    # 1. macOS 11 and later, unconditionally
+    # 2. macOS 10.15 with Xcode 12.2 or later
+    # For now the second category is ignored.
+    osx_version = _get_system_version_tuple()
+    return osx_version >= (11, 0) if osx_version else False
+
 
 def _find_appropriate_compiler(_config_vars):
     """Find appropriate C compiler for extension module builds"""
@@ -331,6 +355,12 @@ def compiler_fixup(compiler_so, cc_args)
             except ValueError:
                 break
 
+    elif not _supports_arm64_builds():
+        # Look for "-arch arm64" and drop that
+        for idx in range(len(compiler_so)):
+            if compiler_so[idx] == '-arch' and compiler_so[idx+1] == "arm64":
+                del compiler_so[idx:idx+2]
+
     if 'ARCHFLAGS' in os.environ and not stripArch:
         # User specified different -arch flags in the environ,
         # see also distutils.sysconfig
@@ -481,6 +511,8 @@ def get_platform_osx(_config_vars, osnam
 
             if len(archs) == 1:
                 machine = archs[0]
+            elif archs == ('arm64', 'x86_64'):
+                machine = 'universal2'
             elif archs == ('i386', 'ppc'):
                 machine = 'fat'
             elif archs == ('i386', 'x86_64'):

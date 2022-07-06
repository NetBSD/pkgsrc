$NetBSD: patch-setup.py,v 1.14 2022/07/06 15:18:17 adam Exp $

Fix libatomic detection.
Use dependencies in pkgsrc.

--- setup.py.orig	2022-06-21 21:07:50.000000000 +0000
+++ setup.py
@@ -316,32 +316,7 @@ EXTENSION_INCLUDE_DIRECTORIES = ((PYTHON
                                  UPBDEFS_GRPC_GENERATED_INCLUDE +
                                  XXHASH_INCLUDE + ZLIB_INCLUDE)
 
-EXTENSION_LIBRARIES = ()
-if "linux" in sys.platform:
-    EXTENSION_LIBRARIES += ('rt',)
-if not "win32" in sys.platform:
-    EXTENSION_LIBRARIES += ('m',)
-if "win32" in sys.platform:
-    EXTENSION_LIBRARIES += (
-        'advapi32',
-        'bcrypt',
-        'dbghelp',
-        'ws2_32',
-    )
-if BUILD_WITH_SYSTEM_OPENSSL:
-    EXTENSION_LIBRARIES += (
-        'ssl',
-        'crypto',
-    )
-if BUILD_WITH_SYSTEM_ZLIB:
-    EXTENSION_LIBRARIES += ('z',)
-if BUILD_WITH_SYSTEM_CARES:
-    EXTENSION_LIBRARIES += ('cares',)
-if BUILD_WITH_SYSTEM_RE2:
-    EXTENSION_LIBRARIES += ('re2',)
-if BUILD_WITH_SYSTEM_ABSL:
-    EXTENSION_LIBRARIES += tuple(
-        lib.stem[3:] for lib in pathlib.Path('/usr').glob('lib*/libabsl_*.so'))
+EXTENSION_LIBRARIES = ('grpc',)
 
 DEFINE_MACROS = (('_WIN32_WINNT', 0x600),)
 asm_files = []
@@ -442,7 +417,7 @@ def cython_extensions_and_necessity():
     ]
     config = os.environ.get('CONFIG', 'opt')
     prefix = 'libs/' + config + '/'
-    if USE_PREBUILT_GRPC_CORE:
+    if False:
         extra_objects = [
             prefix + 'libares.a', prefix + 'libboringssl.a',
             prefix + 'libgpr.a', prefix + 'libgrpc.a'
@@ -454,8 +429,7 @@ def cython_extensions_and_necessity():
     extensions = [
         _extension.Extension(
             name=module_name,
-            sources=([module_file] + list(CYTHON_HELPER_C_FILES) +
-                     core_c_files + asm_files),
+            sources=[module_file] + list(CYTHON_HELPER_C_FILES),
             include_dirs=list(EXTENSION_INCLUDE_DIRECTORIES),
             libraries=list(EXTENSION_LIBRARIES),
             define_macros=list(DEFINE_MACROS),

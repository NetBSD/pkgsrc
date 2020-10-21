$NetBSD: patch-setup.py,v 1.10 2020/10/21 20:01:20 adam Exp $

Fix libatomic detection.
Use dependencies in pkgsrc.

--- setup.py.orig	2020-10-20 20:24:08.000000000 +0000
+++ setup.py
@@ -264,26 +264,7 @@ EXTENSION_INCLUDE_DIRECTORIES = ((PYTHON
                                  UPB_GRPC_GENERATED_INCLUDE +
                                  UPBDEFS_GRPC_GENERATED_INCLUDE + ZLIB_INCLUDE)
 
-EXTENSION_LIBRARIES = ()
-if "linux" in sys.platform:
-    EXTENSION_LIBRARIES += ('rt',)
-if not "win32" in sys.platform:
-    EXTENSION_LIBRARIES += ('m',)
-if "win32" in sys.platform:
-    EXTENSION_LIBRARIES += (
-        'advapi32',
-        'ws2_32',
-        'dbghelp',
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
+EXTENSION_LIBRARIES = ('grpc',)
 
 DEFINE_MACROS = (('_WIN32_WINNT', 0x600),)
 asm_files = []
@@ -361,7 +342,7 @@ def cython_extensions_and_necessity():
     ]
     config = os.environ.get('CONFIG', 'opt')
     prefix = 'libs/' + config + '/'
-    if USE_PREBUILT_GRPC_CORE:
+    if False:
         extra_objects = [
             prefix + 'libares.a', prefix + 'libboringssl.a',
             prefix + 'libgpr.a', prefix + 'libgrpc.a'
@@ -373,8 +354,7 @@ def cython_extensions_and_necessity():
     extensions = [
         _extension.Extension(
             name=module_name,
-            sources=([module_file] + list(CYTHON_HELPER_C_FILES) +
-                     core_c_files + asm_files),
+            sources=[module_file] + list(CYTHON_HELPER_C_FILES),
             include_dirs=list(EXTENSION_INCLUDE_DIRECTORIES),
             libraries=list(EXTENSION_LIBRARIES),
             define_macros=list(DEFINE_MACROS),

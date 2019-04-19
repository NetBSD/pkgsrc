$NetBSD: patch-setup.py,v 1.4 2019/04/19 07:31:47 adam Exp $

Use dependencies in pkgsrc.

--- setup.py.orig	2019-04-15 23:12:51.000000000 +0000
+++ setup.py
@@ -206,19 +206,7 @@ EXTENSION_INCLUDE_DIRECTORIES = (
     (PYTHON_STEM,) + CORE_INCLUDE + SSL_INCLUDE + ZLIB_INCLUDE +
     NANOPB_INCLUDE + CARES_INCLUDE + ADDRESS_SORTING_INCLUDE)
 
-EXTENSION_LIBRARIES = ()
-if "linux" in sys.platform:
-  EXTENSION_LIBRARIES += ('rt',)
-if not "win32" in sys.platform:
-  EXTENSION_LIBRARIES += ('m',)
-if "win32" in sys.platform:
-  EXTENSION_LIBRARIES += ('advapi32', 'ws2_32',)
-if BUILD_WITH_SYSTEM_OPENSSL:
-  EXTENSION_LIBRARIES += ('ssl', 'crypto',)
-if BUILD_WITH_SYSTEM_ZLIB:
-  EXTENSION_LIBRARIES += ('z',)
-if BUILD_WITH_SYSTEM_CARES:
-  EXTENSION_LIBRARIES += ('cares',)
+EXTENSION_LIBRARIES = ('grpc',)
 
 DEFINE_MACROS = (('OPENSSL_NO_ASM', 1), ('_WIN32_WINNT', 0x600))
 if not DISABLE_LIBC_COMPATIBILITY:
@@ -265,7 +253,7 @@ def cython_extensions_and_necessity():
                   for name in CYTHON_EXTENSION_MODULE_NAMES]
   config = os.environ.get('CONFIG', 'opt')
   prefix = 'libs/' + config + '/'
-  if USE_PREBUILT_GRPC_CORE:
+  if False:
     extra_objects = [prefix + 'libares.a',
                      prefix + 'libboringssl.a',
                      prefix + 'libgpr.a',
@@ -277,7 +265,7 @@ def cython_extensions_and_necessity():
   extensions = [
       _extension.Extension(
           name=module_name,
-          sources=[module_file] + list(CYTHON_HELPER_C_FILES) + core_c_files,
+          sources=[module_file] + list(CYTHON_HELPER_C_FILES),
           include_dirs=list(EXTENSION_INCLUDE_DIRECTORIES),
           libraries=list(EXTENSION_LIBRARIES),
           define_macros=list(DEFINE_MACROS),

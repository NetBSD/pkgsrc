$NetBSD: patch-setup.py,v 1.6 2020/04/04 09:30:37 adam Exp $

Fix libatomic detection.
Use dependencies in pkgsrc.

--- setup.py.orig	2020-04-03 01:18:49.000000000 +0000
+++ setup.py
@@ -146,7 +146,7 @@ def check_linker_need_libatomic():
   """Test if linker on system needs libatomic."""
   code_test = (b'#include <atomic>\n' +
                b'int main() { return std::atomic<int64_t>{}; }')
-  cc_test = subprocess.Popen(['cc', '-x', 'c++', '-std=c++11', '-'],
+  cc_test = subprocess.Popen(['c++', '-x', 'c++', '-std=c++11', '-'],
                              stdin=PIPE,
                              stdout=PIPE,
                              stderr=PIPE)
@@ -235,19 +235,7 @@ EXTENSION_INCLUDE_DIRECTORIES = (
     UPB_GRPC_GENERATED_INCLUDE +
     ZLIB_INCLUDE)
 
-EXTENSION_LIBRARIES = ()
-if "linux" in sys.platform:
-  EXTENSION_LIBRARIES += ('rt',)
-if not "win32" in sys.platform:
-  EXTENSION_LIBRARIES += ('m',)
-if "win32" in sys.platform:
-  EXTENSION_LIBRARIES += ('advapi32', 'ws2_32', 'dbghelp',)
-if BUILD_WITH_SYSTEM_OPENSSL:
-  EXTENSION_LIBRARIES += ('ssl', 'crypto',)
-if BUILD_WITH_SYSTEM_ZLIB:
-  EXTENSION_LIBRARIES += ('z',)
-if BUILD_WITH_SYSTEM_CARES:
-  EXTENSION_LIBRARIES += ('cares',)
+EXTENSION_LIBRARIES = ('grpc',)
 
 DEFINE_MACROS = (('OPENSSL_NO_ASM', 1), ('_WIN32_WINNT', 0x600))
 if not DISABLE_LIBC_COMPATIBILITY:
@@ -295,7 +283,7 @@ def cython_extensions_and_necessity():
                   for name in CYTHON_EXTENSION_MODULE_NAMES]
   config = os.environ.get('CONFIG', 'opt')
   prefix = 'libs/' + config + '/'
-  if USE_PREBUILT_GRPC_CORE:
+  if False:
     extra_objects = [prefix + 'libares.a',
                      prefix + 'libboringssl.a',
                      prefix + 'libgpr.a',
@@ -307,7 +295,7 @@ def cython_extensions_and_necessity():
   extensions = [
       _extension.Extension(
           name=module_name,
-          sources=[module_file] + list(CYTHON_HELPER_C_FILES) + core_c_files,
+          sources=[module_file] + list(CYTHON_HELPER_C_FILES),
           include_dirs=list(EXTENSION_INCLUDE_DIRECTORIES),
           libraries=list(EXTENSION_LIBRARIES),
           define_macros=list(DEFINE_MACROS),

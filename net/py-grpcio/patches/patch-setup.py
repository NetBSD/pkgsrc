$NetBSD: patch-setup.py,v 1.17 2024/05/15 21:13:50 wiz Exp $

Fix libatomic detection.
Use dependencies in pkgsrc.

--- setup.py.orig	2024-04-26 06:29:21.000000000 +0000
+++ setup.py
@@ -335,34 +335,7 @@ EXTENSION_INCLUDE_DIRECTORIES = (
     + ZLIB_INCLUDE
 )
 
-EXTENSION_LIBRARIES = ()
-if "linux" in sys.platform:
-    EXTENSION_LIBRARIES += ("rt",)
-if not "win32" in sys.platform:
-    EXTENSION_LIBRARIES += ("m",)
-if "win32" in sys.platform:
-    EXTENSION_LIBRARIES += (
-        "advapi32",
-        "bcrypt",
-        "dbghelp",
-        "ws2_32",
-    )
-if BUILD_WITH_SYSTEM_OPENSSL:
-    EXTENSION_LIBRARIES += (
-        "ssl",
-        "crypto",
-    )
-if BUILD_WITH_SYSTEM_ZLIB:
-    EXTENSION_LIBRARIES += ("z",)
-if BUILD_WITH_SYSTEM_CARES:
-    EXTENSION_LIBRARIES += ("cares",)
-if BUILD_WITH_SYSTEM_RE2:
-    EXTENSION_LIBRARIES += ("re2",)
-if BUILD_WITH_SYSTEM_ABSL:
-    EXTENSION_LIBRARIES += tuple(
-        lib.stem[3:]
-        for lib in sorted(pathlib.Path("/usr").glob("lib*/libabsl_*.so"))
-    )
+EXTENSION_LIBRARIES = ('grpc',)
 
 DEFINE_MACROS = (("_WIN32_WINNT", 0x600),)
 asm_files = []
@@ -466,7 +439,7 @@ def cython_extensions_and_necessity():
     ]
     config = os.environ.get("CONFIG", "opt")
     prefix = "libs/" + config + "/"
-    if USE_PREBUILT_GRPC_CORE:
+    if False:
         extra_objects = [
             prefix + "libares.a",
             prefix + "libboringssl.a",
@@ -483,8 +456,6 @@ def cython_extensions_and_necessity():
             sources=(
                 [module_file]
                 + list(CYTHON_HELPER_C_FILES)
-                + core_c_files
-                + asm_files
             ),
             include_dirs=list(EXTENSION_INCLUDE_DIRECTORIES),
             libraries=list(EXTENSION_LIBRARIES),

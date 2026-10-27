$NetBSD: patch-setup.py,v 1.10 2026/10/27 08:02:48 adam Exp $

Use pthread on FreeBSD.
Use external protobuf.

--- setup.py.orig	2026-10-25 14:42:05.000000000 +0000
+++ setup.py
@@ -229,7 +229,7 @@ if EXTRA_ENV_LINK_ARGS is None:
         EXTRA_ENV_LINK_ARGS += " -Wl,-exported_symbol,_{}".format(
             _EXT_INIT_SYMBOL
         )
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += " -lpthread"
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += " -latomic"
@@ -255,15 +255,11 @@ def _get_cc_files():
     return [os.path.normpath(cc_file) for cc_file in cc_files]
 
 
-CC_FILES = _get_cc_files()
 
 
 PROTO_FILES = [
     os.path.normpath(proto_file) for proto_file in protoc_lib_deps.PROTO_FILES
 ]
-CC_INCLUDES = [
-    os.path.normpath(include_dir) for include_dir in protoc_lib_deps.CC_INCLUDES
-]
 PROTO_INCLUDE = os.path.normpath(protoc_lib_deps.PROTO_INCLUDE)
 PROTO_PATH_PREFIX = os.path.normpath("google/protobuf")
 
@@ -279,7 +275,7 @@ if "win32" in sys.platform:
     )
     if "64bit" in platform.architecture()[0]:
         DEFINE_MACROS += (("MS_WIN64", 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (("HAVE_PTHREAD", 1),)
 
 
@@ -318,7 +314,7 @@ def extension_modules():
         os.path.join("grpc_tools", "main.cc"),
         os.path.join("grpc_root", "src", "compiler", "python_generator.cc"),
         os.path.join("grpc_root", "src", "compiler", "proto_parser_helper.cc"),
-    ] + CC_FILES
+    ]
 
     plugin_ext = Extension(
         name="grpc_tools._protoc_compiler",
@@ -327,8 +323,7 @@ def extension_modules():
             ".",
             "grpc_root",
             os.path.join("grpc_root", "include"),
-        ]
-        + CC_INCLUDES,
+        ],
         define_macros=list(DEFINE_MACROS),
         extra_compile_args=list(EXTRA_COMPILE_ARGS),
         extra_link_args=list(EXTRA_LINK_ARGS),

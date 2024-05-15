$NetBSD: patch-setup.py,v 1.8 2024/05/15 21:13:50 wiz Exp $

Use pthread on FreeBSD.
Use external protobuf.

--- setup.py.orig	2024-04-26 06:29:22.000000000 +0000
+++ setup.py
@@ -211,7 +211,7 @@ if EXTRA_ENV_LINK_ARGS is None:
         EXTRA_ENV_LINK_ARGS += " -Wl,-exported_symbol,_{}".format(
             _EXT_INIT_SYMBOL
         )
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += " -lpthread"
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += " -latomic"
@@ -227,13 +227,9 @@ EXTRA_LINK_ARGS = shlex.split(EXTRA_ENV_
 if BUILD_WITH_STATIC_LIBSTDCXX:
     EXTRA_LINK_ARGS.append("-static-libstdc++")
 
-CC_FILES = [os.path.normpath(cc_file) for cc_file in protoc_lib_deps.CC_FILES]
 PROTO_FILES = [
     os.path.normpath(proto_file) for proto_file in protoc_lib_deps.PROTO_FILES
 ]
-CC_INCLUDES = [
-    os.path.normpath(include_dir) for include_dir in protoc_lib_deps.CC_INCLUDES
-]
 PROTO_INCLUDE = os.path.normpath(protoc_lib_deps.PROTO_INCLUDE)
 
 GRPC_PYTHON_TOOLS_PACKAGE = "grpc_tools"
@@ -248,7 +244,7 @@ if "win32" in sys.platform:
     )
     if "64bit" in platform.architecture()[0]:
         DEFINE_MACROS += (("MS_WIN64", 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (("HAVE_PTHREAD", 1),)
 
 
@@ -286,7 +282,7 @@ def extension_modules():
         os.path.join("grpc_tools", "main.cc"),
         os.path.join("grpc_root", "src", "compiler", "python_generator.cc"),
         os.path.join("grpc_root", "src", "compiler", "proto_parser_helper.cc"),
-    ] + CC_FILES
+    ]
 
     plugin_ext = Extension(
         name="grpc_tools._protoc_compiler",
@@ -295,8 +291,7 @@ def extension_modules():
             ".",
             "grpc_root",
             os.path.join("grpc_root", "include"),
-        ]
-        + CC_INCLUDES,
+        ],
         define_macros=list(DEFINE_MACROS),
         extra_compile_args=list(EXTRA_COMPILE_ARGS),
         extra_link_args=list(EXTRA_LINK_ARGS),

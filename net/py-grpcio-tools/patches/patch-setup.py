$NetBSD: patch-setup.py,v 1.6 2023/04/27 06:31:12 wiz Exp $

Use pthread on FreeBSD.
Use external protobuf.

--- setup.py.orig	2023-04-13 00:50:54.000000000 +0000
+++ setup.py
@@ -175,7 +175,7 @@ if EXTRA_ENV_LINK_ARGS is None:
     if "darwin" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -Wl,-exported_symbol,_{}'.format(
             _EXT_INIT_SYMBOL)
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -lpthread'
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += ' -latomic'
@@ -191,11 +191,9 @@ EXTRA_LINK_ARGS = shlex.split(EXTRA_ENV_
 if BUILD_WITH_STATIC_LIBSTDCXX:
     EXTRA_LINK_ARGS.append('-static-libstdc++')
 
-CC_FILES = [os.path.normpath(cc_file) for cc_file in protoc_lib_deps.CC_FILES]
 PROTO_FILES = [
     os.path.normpath(proto_file) for proto_file in protoc_lib_deps.PROTO_FILES
 ]
-CC_INCLUDE = os.path.normpath(protoc_lib_deps.CC_INCLUDE)
 PROTO_INCLUDE = os.path.normpath(protoc_lib_deps.PROTO_INCLUDE)
 
 GRPC_PYTHON_TOOLS_PACKAGE = 'grpc_tools'
@@ -206,7 +204,7 @@ if "win32" in sys.platform:
     DEFINE_MACROS += (('WIN32_LEAN_AND_MEAN', 1),)
     if '64bit' in platform.architecture()[0]:
         DEFINE_MACROS += (('MS_WIN64', 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (('HAVE_PTHREAD', 1),)
 
 # By default, Python3 distutils enforces compatibility of
@@ -254,7 +252,7 @@ def extension_modules():
         os.path.join('grpc_tools', 'main.cc'),
         os.path.join('grpc_root', 'src', 'compiler', 'python_generator.cc'),
         os.path.join('grpc_root', 'src', 'compiler', 'proto_parser_helper.cc')
-    ] + [os.path.join(CC_INCLUDE, cc_file) for cc_file in CC_FILES]
+    ]
 
     plugin_ext = extension.Extension(
         name='grpc_tools._protoc_compiler',
@@ -263,7 +261,6 @@ def extension_modules():
             '.',
             'grpc_root',
             os.path.join('grpc_root', 'include'),
-            CC_INCLUDE,
         ],
         language='c++',
         define_macros=list(DEFINE_MACROS),

$NetBSD: patch-setup.py,v 1.5 2021/04/16 09:20:01 adam Exp $

Use pthread on FreeBSD.
Use external protobuf.

--- setup.py.orig	2021-04-07 05:49:06.000000000 +0000
+++ setup.py
@@ -180,7 +180,7 @@ if EXTRA_ENV_LINK_ARGS is None:
     if "darwin" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -Wl,-exported_symbol,_{}'.format(
             _EXT_INIT_SYMBOL)
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -lpthread'
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += ' -latomic'
@@ -196,11 +196,9 @@ EXTRA_LINK_ARGS = shlex.split(EXTRA_ENV_
 if BUILD_WITH_STATIC_LIBSTDCXX:
     EXTRA_LINK_ARGS.append('-static-libstdc++')
 
-CC_FILES = [os.path.normpath(cc_file) for cc_file in protoc_lib_deps.CC_FILES]
 PROTO_FILES = [
     os.path.normpath(proto_file) for proto_file in protoc_lib_deps.PROTO_FILES
 ]
-CC_INCLUDE = os.path.normpath(protoc_lib_deps.CC_INCLUDE)
 PROTO_INCLUDE = os.path.normpath(protoc_lib_deps.PROTO_INCLUDE)
 
 GRPC_PYTHON_TOOLS_PACKAGE = 'grpc_tools'
@@ -211,7 +209,7 @@ if "win32" in sys.platform:
     DEFINE_MACROS += (('WIN32_LEAN_AND_MEAN', 1),)
     if '64bit' in platform.architecture()[0]:
         DEFINE_MACROS += (('MS_WIN64', 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (('HAVE_PTHREAD', 1),)
 
 # By default, Python3 distutils enforces compatibility of
@@ -258,7 +256,7 @@ def extension_modules():
     plugin_sources += [
         os.path.join('grpc_tools', 'main.cc'),
         os.path.join('grpc_root', 'src', 'compiler', 'python_generator.cc')
-    ] + [os.path.join(CC_INCLUDE, cc_file) for cc_file in CC_FILES]
+    ]
 
     plugin_ext = extension.Extension(
         name='grpc_tools._protoc_compiler',
@@ -267,7 +265,6 @@ def extension_modules():
             '.',
             'grpc_root',
             os.path.join('grpc_root', 'include'),
-            CC_INCLUDE,
         ],
         language='c++',
         define_macros=list(DEFINE_MACROS),

$NetBSD: patch-setup.py,v 1.2 2019/04/19 09:58:50 adam Exp $

Use pthread on FreeBSD.
Use external protobuf.

--- setup.py.orig	2019-04-15 23:12:52.000000000 +0000
+++ setup.py
@@ -88,7 +88,7 @@ if EXTRA_ENV_COMPILE_ARGS is None:
         EXTRA_ENV_COMPILE_ARGS += ' -fno-wrapv -frtti'
 if EXTRA_ENV_LINK_ARGS is None:
     EXTRA_ENV_LINK_ARGS = ''
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -lpthread'
     elif "win32" in sys.platform and sys.version_info < (3, 5):
         msvcr = cygwinccompiler.get_msvcr()[0]
@@ -101,11 +101,9 @@ if EXTRA_ENV_LINK_ARGS is None:
 EXTRA_COMPILE_ARGS = shlex.split(EXTRA_ENV_COMPILE_ARGS)
 EXTRA_LINK_ARGS = shlex.split(EXTRA_ENV_LINK_ARGS)
 
-CC_FILES = [os.path.normpath(cc_file) for cc_file in protoc_lib_deps.CC_FILES]
 PROTO_FILES = [
     os.path.normpath(proto_file) for proto_file in protoc_lib_deps.PROTO_FILES
 ]
-CC_INCLUDE = os.path.normpath(protoc_lib_deps.CC_INCLUDE)
 PROTO_INCLUDE = os.path.normpath(protoc_lib_deps.PROTO_INCLUDE)
 
 GRPC_PYTHON_TOOLS_PACKAGE = 'grpc_tools'
@@ -116,7 +114,7 @@ if "win32" in sys.platform:
     DEFINE_MACROS += (('WIN32_LEAN_AND_MEAN', 1),)
     if '64bit' in platform.architecture()[0]:
         DEFINE_MACROS += (('MS_WIN64', 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (('HAVE_PTHREAD', 1),)
 
 # By default, Python3 distutils enforces compatibility of
@@ -163,7 +161,7 @@ def extension_modules():
     plugin_sources += [
         os.path.join('grpc_tools', 'main.cc'),
         os.path.join('grpc_root', 'src', 'compiler', 'python_generator.cc')
-    ] + [os.path.join(CC_INCLUDE, cc_file) for cc_file in CC_FILES]
+    ]
 
     plugin_ext = extension.Extension(
         name='grpc_tools._protoc_compiler',
@@ -172,7 +170,6 @@ def extension_modules():
             '.',
             'grpc_root',
             os.path.join('grpc_root', 'include'),
-            CC_INCLUDE,
         ],
         language='c++',
         define_macros=list(DEFINE_MACROS),

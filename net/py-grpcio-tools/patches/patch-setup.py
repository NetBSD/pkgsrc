$NetBSD: patch-setup.py,v 1.1 2018/04/28 13:57:05 minskim Exp $

Use pthread on FreeBSD.

--- setup.py.orig	2018-04-13 19:56:09.000000000 +0000
+++ setup.py
@@ -85,7 +85,7 @@ if EXTRA_ENV_COMPILE_ARGS is None:
         EXTRA_ENV_COMPILE_ARGS += ' -fno-wrapv -frtti'
 if EXTRA_ENV_LINK_ARGS is None:
     EXTRA_ENV_LINK_ARGS = ''
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -lpthread'
     elif "win32" in sys.platform and sys.version_info < (3, 5):
         msvcr = cygwinccompiler.get_msvcr()[0]
@@ -113,7 +113,7 @@ if "win32" in sys.platform:
     DEFINE_MACROS += (('WIN32_LEAN_AND_MEAN', 1),)
     if '64bit' in platform.architecture()[0]:
         DEFINE_MACROS += (('MS_WIN64', 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (('HAVE_PTHREAD', 1),)
 
 # By default, Python3 distutils enforces compatibility of

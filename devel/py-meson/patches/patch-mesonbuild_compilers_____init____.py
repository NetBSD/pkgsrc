$NetBSD: patch-mesonbuild_compilers_____init____.py,v 1.1 2018/05/15 09:04:37 jperkin Exp $

Support SunOS-specific GCC behaviour.

--- mesonbuild/compilers/__init__.py.orig	2017-07-21 20:07:34.000000000 +0000
+++ mesonbuild/compilers/__init__.py
@@ -20,6 +20,7 @@ __all__ = [
     'GCC_CYGWIN',
     'GCC_MINGW',
     'GCC_OSX',
+    'GCC_SUNOS',
     'GCC_STANDARD',
     'ICC_OSX',
     'ICC_STANDARD',
@@ -84,6 +85,7 @@ __all__ = [
 # Bring symbols from each module into compilers sub-package namespace
 from .compilers import (
     GCC_OSX,
+    GCC_SUNOS,
     GCC_MINGW,
     GCC_CYGWIN,
     GCC_STANDARD,

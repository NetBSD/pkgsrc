$NetBSD: patch-src_types.h,v 1.2 2020/11/21 22:33:59 adam Exp $

Builds and tests fine against newer libgit2.

--- src/types.h.orig	2020-10-14 06:40:15.000000000 +0000
+++ src/types.h
@@ -32,9 +32,6 @@
 #include <Python.h>
 #include <git2.h>
 
-#if !(LIBGIT2_VER_MAJOR == 1 && LIBGIT2_VER_MINOR == 1)
-#error You need a compatible libgit2 version (1.1.x)
-#endif
 
 /*
  * Python objects

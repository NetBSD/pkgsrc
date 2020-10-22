$NetBSD: patch-src_types.h,v 1.1 2020/10/22 16:24:10 jperkin Exp $

Builds and tests fine against libgit2 1.1.x.

--- src/types.h.orig	2020-07-24 11:39:38.000000000 +0000
+++ src/types.h
@@ -32,10 +32,6 @@
 #include <Python.h>
 #include <git2.h>
 
-#if !(LIBGIT2_VER_MAJOR == 1 && LIBGIT2_VER_MINOR == 0)
-#error You need a compatible libgit2 version (1.0.x)
-#endif
-
 /*
  * Python objects
  *

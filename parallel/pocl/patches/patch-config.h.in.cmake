$NetBSD: patch-config.h.in.cmake,v 1.2 2021/06/10 12:26:26 nia Exp $

Fix detection of dlopen
https://github.com/pocl/pocl/pull/950

--- config.h.in.cmake.orig	2021-05-19 08:12:19.000000000 +0000
+++ config.h.in.cmake
@@ -35,6 +35,8 @@
 
 #cmakedefine ENABLE_SPIRV
 
+#cmakedefine HAVE_DLFCN_H
+
 #cmakedefine HAVE_FORK
 
 #cmakedefine HAVE_VFORK
@@ -57,8 +59,6 @@
 
 #cmakedefine HAVE_LTTNG_UST
 
-#cmakedefine HAVE_LIBDL
-
 #cmakedefine HAVE_OCL_ICD
 
 #cmakedefine HAVE_POSIX_MEMALIGN

$NetBSD: patch-modules_core_src_parallel.cpp,v 1.1 2021/10/06 21:10:24 adam Exp $

NetBSD support.

--- modules/core/src/parallel.cpp.orig	2021-10-06 20:27:21.320272155 +0000
+++ modules/core/src/parallel.cpp
@@ -55,7 +55,7 @@
 
 #if defined __linux__ || defined __APPLE__ || defined __GLIBC__ \
     || defined __HAIKU__ || defined __EMSCRIPTEN__ || defined __FreeBSD__ \
-    || defined __OpenBSD__
+    || defined __OpenBSD__ || defined __NetBSD__
     #include <unistd.h>
     #include <stdio.h>
     #include <sys/types.h>

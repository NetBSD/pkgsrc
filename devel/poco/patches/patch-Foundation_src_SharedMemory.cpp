$NetBSD: patch-Foundation_src_SharedMemory.cpp,v 1.2 2012/07/29 11:26:54 fhajny Exp $

Do not mangle _XOPEN_SOURCE when GCC is used, rely on CXXFLAGS instead.
--- Foundation/src/SharedMemory.cpp.orig	2011-09-24 08:07:00.000000000 +0000
+++ Foundation/src/SharedMemory.cpp
@@ -34,7 +34,7 @@
 //
 
 
-#if defined(__sun)
+#if defined(__sun) && !defined(__GNUC__)
 #undef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 500
 #endif

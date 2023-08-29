$NetBSD: patch-SharedMemory.cpp,v 1.2 2023/08/29 21:49:57 bacon Exp $

# Portability

--- SharedMemory.cpp.orig	2022-11-01 14:50:35.000000000 +0000
+++ SharedMemory.cpp
@@ -12,7 +12,7 @@
 #include <errno.h>
 #include <sys/types.h>
 
-#if defined(COMPILE_FOR_MAC) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
   //some Mac's idiosyncrasies: standard SHM libraries are very old and missing some definitions
   #define SHM_NORESERVE 0
 #endif

$NetBSD: patch-src_memory.c,v 1.1 2025/08/08 07:24:00 adam Exp $

BSD support https://github.com/hashcat/hashcat/pull/4392

--- src/memory.c.orig	2025-08-01 21:03:55.000000000 +0000
+++ src/memory.c
@@ -71,7 +71,8 @@ void *hc_alloc_aligned (size_t alignment
 {
   void *ptr = NULL;
 
-  #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined (__CYGWIN__) || defined (__MSYS__)
+  #if defined (__linux__)   || defined (__APPLE__)     || defined (__OpenBSD__) || defined (__NetBSD__) || \
+      defined (__FreeBSD__) || defined (__DragonFly__) || defined (__CYGWIN__)  || defined (__MSYS__)
 
   if (posix_memalign (&ptr, alignment, size) != 0)
   {

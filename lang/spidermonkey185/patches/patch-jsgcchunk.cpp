$NetBSD: patch-jsgcchunk.cpp,v 1.2.2.2 2018/05/06 08:45:41 spz Exp $

Limit mmap() to the lower 32 bits of address space on SunOS, as SpiderMonkey
makes assumptions: https://bugzilla.mozilla.org/show_bug.cgi?id=577056

--- jsgcchunk.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsgcchunk.cpp
@@ -303,7 +303,7 @@ MapAlignedPages(size_t size, size_t alig
      */
 #ifdef SOLARIS
     void *p = mmap((caddr_t) alignment, size, PROT_READ | PROT_WRITE,
-                     MAP_PRIVATE | MAP_NOSYNC | MAP_ALIGN | MAP_ANON, -1, 0);
+                     MAP_PRIVATE | MAP_NOSYNC | MAP_ALIGN | MAP_ANON | MAP_32BIT, -1, 0);
 #else
     void *p = mmap((void *) alignment, size, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_NOSYNC | MAP_ALIGN | MAP_ANON, -1, 0);

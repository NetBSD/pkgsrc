$NetBSD: patch-src_data_memory__chunk.cc,v 1.2 2026/04/23 13:51:33 adam Exp $

Fix Sun-specific definition of madvise.

--- src/data/memory_chunk.cc.orig	2026-04-23 08:31:38.000000000 +0000
+++ src/data/memory_chunk.cc
@@ -8,7 +8,7 @@
 
 #ifdef __sun__
 
-extern "C" int madvise(void *, size_t, int);
+extern "C" int madvise(caddr_t, size_t, int);
 //#include <sys/mman.h>
 //Should be the include line instead, but Solaris
 //has an annoying bug wherein it doesn't declare

$NetBSD: patch-src_data_memory__chunk.cc,v 1.1 2023/11/06 11:26:45 nia Exp $

Fix Sun-specific definition of madvise.

--- src/data/memory_chunk.cc.orig	2019-07-19 11:44:08.000000000 +0000
+++ src/data/memory_chunk.cc
@@ -45,7 +45,7 @@
 #include "memory_chunk.h"
 
 #ifdef __sun__
-extern "C" int madvise(void *, size_t, int);
+extern "C" int madvise(caddr_t, size_t, int);
 //#include <sys/mman.h>
 //Should be the include line instead, but Solaris
 //has an annoying bug wherein it doesn't declare

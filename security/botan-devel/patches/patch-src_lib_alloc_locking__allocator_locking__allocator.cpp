$NetBSD: patch-src_lib_alloc_locking__allocator_locking__allocator.cpp,v 1.3 2015/05/20 21:57:10 joerg Exp $

--- src/lib/alloc/locking_allocator/locking_allocator.cpp.orig	2015-05-19 20:33:25.000000000 +0000
+++ src/lib/alloc/locking_allocator/locking_allocator.cpp
@@ -8,6 +8,7 @@
 #include <botan/locking_allocator.h>
 #include <botan/mem_ops.h>
 #include <algorithm>
+#include <cstdlib>
 #include <string>
 
 #include <sys/mman.h>

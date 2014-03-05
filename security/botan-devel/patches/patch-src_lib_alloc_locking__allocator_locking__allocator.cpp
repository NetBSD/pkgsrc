$NetBSD: patch-src_lib_alloc_locking__allocator_locking__allocator.cpp,v 1.1 2014/03/05 21:22:38 joerg Exp $

--- src/lib/alloc/locking_allocator/locking_allocator.cpp.orig	2014-02-14 02:36:03.000000000 +0000
+++ src/lib/alloc/locking_allocator/locking_allocator.cpp
@@ -7,9 +7,10 @@
 
 #include <botan/locking_allocator.h>
 #include <botan/mem_ops.h>
-#include <algorithm>
 #include <sys/mman.h>
 #include <sys/resource.h>
+#include <algorithm>
+#include <string>
 
 namespace Botan {
 
@@ -213,6 +214,9 @@ mlock_allocator::mlock_allocator() :
 #if !defined(MAP_NOCORE)
    #define MAP_NOCORE 0
 #endif
+#if !defined(MAP_ANONYMOUS)
+   #define MAP_ANONYMOUS MAP_ANON
+#endif
 
    if(m_poolsize)
       {

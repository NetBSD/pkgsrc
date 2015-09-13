$NetBSD: patch-src_lib_alloc_locking__allocator_locking__allocator.cpp,v 1.4 2015/09/13 02:31:22 joerg Exp $

--- src/lib/alloc/locking_allocator/locking_allocator.cpp.orig	2015-03-30 02:14:22.000000000 +0000
+++ src/lib/alloc/locking_allocator/locking_allocator.cpp
@@ -8,10 +8,14 @@
 #include <botan/locking_allocator.h>
 #include <botan/mem_ops.h>
 #include <algorithm>
+#include <cstdlib>
 #include <string>
 
 #include <sys/mman.h>
 #include <sys/resource.h>
+#ifdef __sun
+#include <priv.h>
+#endif
 
 namespace Botan {
 
@@ -25,6 +31,7 @@ const size_t ALIGNMENT_MULTIPLE = 2;
 
 size_t reset_mlock_limit(size_t max_req)
    {
+#ifdef RLIMIT_MEMLOCK
    struct rlimit limits;
    ::getrlimit(RLIMIT_MEMLOCK, &limits);
 
@@ -36,6 +39,22 @@ size_t reset_mlock_limit(size_t max_req)
       }
 
    return std::min<size_t>(limits.rlim_cur, max_req);
+#elif defined(__sun)
+   priv_set_t *priv_set = priv_allocset();
+   if (priv_set == nullptr)
+     return 0;
+   bool can_mlock = false;
+
+   if(getppriv(PRIV_EFFECTIVE, priv_set) == 0)
+     can_mlock = priv_ismember(priv_set, PRIV_PROC_LOCK_MEMORY);
+
+   priv_freeset(priv_set);
+
+   /* XXX how to obtain the real limit? */
+   return can_mlock ? std::min<size_t>(512 * 1024, max_req) : 0;
+#else
+   return 0;
+#endif
    }
 
 size_t mlock_limit()

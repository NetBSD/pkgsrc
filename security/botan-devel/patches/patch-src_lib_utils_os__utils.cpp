$NetBSD: patch-src_lib_utils_os__utils.cpp,v 1.1 2016/05/19 21:58:43 joerg Exp $

--- src/lib/utils/os_utils.cpp.orig	2016-03-21 01:26:12.000000000 +0000
+++ src/lib/utils/os_utils.cpp
@@ -19,6 +19,10 @@
   #include <unistd.h>
 #endif
 
+#ifdef __sun
+#include <priv.h>
+#endif
+
 #if defined(BOTAN_TARGET_OS_TYPE_IS_WINDOWS)
   #include <windows.h>
 #endif
@@ -171,6 +175,19 @@ size_t get_memory_locking_limit()
          return BOTAN_MLOCK_ALLOCATOR_MAX_LOCKED_KB * 1024ULL;
          }
       }
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
 #endif
 
    return 0;

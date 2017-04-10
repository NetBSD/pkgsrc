$NetBSD: patch-src_lib_utils_os__utils.cpp,v 1.5 2017/04/10 21:14:45 joerg Exp $

--- src/lib/utils/os_utils.cpp.orig	2017-04-05 01:09:22.000000000 +0000
+++ src/lib/utils/os_utils.cpp
@@ -21,6 +21,10 @@
   #include <setjmp.h>
 #endif
 
+#ifdef __sun
+#include <priv.h>
+#endif
+
 #if defined(BOTAN_TARGET_OS_IS_WINDOWS) || defined(BOTAN_TARGET_OS_IS_MINGW)
   #define NOMINMAX 1
   #include <windows.h>
@@ -170,7 +174,21 @@ uint64_t OS::get_system_timestamp_ns()
 
 size_t OS::get_memory_locking_limit()
    {
-#if defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
+#if defined(__sun)
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
+   size_t mlock_requested = BOTAN_MLOCK_ALLOCATOR_MAX_LOCKED_KB;
+   return can_mlock ? std::min<size_t>(512 * 1024, mlock_requested) : 0;
+#elif defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
    /*
    * Linux defaults to only 64 KiB of mlockable memory per process
    * (too small) but BSDs offer a small fraction of total RAM (more

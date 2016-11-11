$NetBSD: patch-src_lib_utils_os__utils.cpp,v 1.3 2016/11/11 19:44:51 joerg Exp $

--- src/lib/utils/os_utils.cpp.orig	2016-10-26 13:39:08.000000000 +0000
+++ src/lib/utils/os_utils.cpp
@@ -19,6 +19,10 @@
   #include <unistd.h>
 #endif
 
+#ifdef __sun
+#include <priv.h>
+#endif
+
 #if defined(BOTAN_TARGET_OS_IS_WINDOWS) || defined(BOTAN_TARGET_OS_IS_MINGW)
   #include <windows.h>
 #endif
@@ -146,7 +150,20 @@ uint64_t get_system_timestamp_ns()
 
 size_t get_memory_locking_limit()
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
+   return can_mlock ? std::min<size_t>(512 * 1024, max_req) : 0;
+#elif defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
    /*
    * Linux defaults to only 64 KiB of mlockable memory per process
    * (too small) but BSDs offer a small fraction of total RAM (more

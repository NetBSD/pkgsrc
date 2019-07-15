$NetBSD: patch-src_lib_utils_os__utils.cpp,v 1.6 2019/07/15 18:31:29 bsiegert Exp $

--- src/lib/utils/os_utils.cpp.orig	2019-07-15 18:14:39.932394200 +0000
+++ src/lib/utils/os_utils.cpp
@@ -325,7 +325,21 @@ size_t OS::system_page_size()
 
 size_t OS::get_memory_locking_limit()
    {
-#if defined(BOTAN_TARGET_OS_HAS_POSIX1) && defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK) && defined(RLIMIT_MEMLOCK)
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
+#elif defined(BOTAN_TARGET_OS_HAS_POSIX1) && defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK) && defined(RLIMIT_MEMLOCK)
    /*
    * If RLIMIT_MEMLOCK is not defined, likely the OS does not support
    * unprivileged mlock calls.

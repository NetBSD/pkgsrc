$NetBSD: patch-src_lib_caching_ksdcmapping__p.h,v 1.1 2024/06/21 10:38:10 jperkin Exp $

Support systems that lack RLIMIT_MEMLOCK.

--- src/lib/caching/ksdcmapping_p.h.orig	2024-06-21 10:28:04.989153487 +0000
+++ src/lib/caching/ksdcmapping_p.h
@@ -191,6 +191,7 @@ private:
             // the size to be able to access every entry, so fixup the mapping.
             if (mapAddress != MAP_FAILED) {
                 // Successful mmap doesn't actually mean that whole range is readable so ensure it is
+#ifdef RLIMIT_MEMLOCK
                 struct rlimit memlock;
                 if (getrlimit(RLIMIT_MEMLOCK, &memlock) == 0 && memlock.rlim_cur >= 2) {
                     // Half of limit in case something else has already locked some mem
@@ -207,6 +208,7 @@ private:
                 } else {
                     qCWarning(KCOREADDONS_DEBUG) << "Failed to get RLIMIT_MEMLOCK!";
                 }
+#endif
 
                 SharedMemory *mapped = reinterpret_cast<SharedMemory *>(mapAddress);
 

$NetBSD: patch-src_hotspot_os_posix_os__posix.cpp,v 1.1 2026/09/26 12:54:51 tnn Exp $

NetBSD 9 has no PTHREAD_STACK_MIN declaration.

--- src/hotspot/os/posix/os_posix.cpp.orig	2026-09-05 19:12:57.352207078 +0000
+++ src/hotspot/os/posix/os_posix.cpp
@@ -105,6 +105,9 @@ static int clock_tics_per_sec = 100;
 static int clock_tics_per_sec = 100;
 
 // Platform minimum stack allowed
+#if defined(__NetBSD__) && !defined(PTHREAD_STACK_MIN)
+#define PTHREAD_STACK_MIN 4096 /* MIN_PAGE_SIZE */
+#endif
 size_t os::_os_min_stack_allowed = PTHREAD_STACK_MIN;
 
 // Check core dump limit and report possible place where core can be found

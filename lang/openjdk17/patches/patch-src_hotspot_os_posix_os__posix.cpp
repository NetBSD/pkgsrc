$NetBSD: patch-src_hotspot_os_posix_os__posix.cpp,v 1.1 2022/05/13 14:24:19 ryoon Exp $

Something is wrong with pthread_condattr_setclock.
We hit assertions in fastdebug builds.
Disable pthread_condattr_setclock for now.

--- src/hotspot/os/posix/os_posix.cpp.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/hotspot/os/posix/os_posix.cpp
@@ -1266,6 +1266,7 @@ void os::Posix::init(void) {
 
   // Check for pthread_condattr_setclock support.
 
+#if !defined(__NetBSD__)
   // libpthread is already loaded.
   int (*condattr_setclock_func)(pthread_condattr_t*, clockid_t) =
     (int (*)(pthread_condattr_t*, clockid_t))dlsym(RTLD_DEFAULT,
@@ -1273,6 +1274,7 @@ void os::Posix::init(void) {
   if (condattr_setclock_func != NULL) {
     _pthread_condattr_setclock = condattr_setclock_func;
   }
+#endif
 
   // Now do general initialization.
 

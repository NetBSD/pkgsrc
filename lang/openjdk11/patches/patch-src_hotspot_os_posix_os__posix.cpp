$NetBSD: patch-src_hotspot_os_posix_os__posix.cpp,v 1.1 2019/10/01 12:36:34 tnn Exp $

Something is wrong with pthread_condattr_setclock.
We hit assertions in fastdebug builds.
Disable pthread_condattr_setclock for now.

--- src/hotspot/os/posix/os_posix.cpp.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/hotspot/os/posix/os_posix.cpp
@@ -1773,6 +1773,7 @@ void os::Posix::init(void) {
 
   _pthread_condattr_setclock = NULL;
 
+#if !defined(__NetBSD__)
   // libpthread is already loaded.
   int (*condattr_setclock_func)(pthread_condattr_t*, clockid_t) =
     (int (*)(pthread_condattr_t*, clockid_t))dlsym(RTLD_DEFAULT,
@@ -1780,6 +1781,7 @@ void os::Posix::init(void) {
   if (condattr_setclock_func != NULL) {
     _pthread_condattr_setclock = condattr_setclock_func;
   }
+#endif
 
   // Now do general initialization.
 

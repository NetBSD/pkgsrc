$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.1 2019/10/01 12:36:34 tnn Exp $

On NetBSD, __sigaction14 should be used as sigaction.

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2019-09-19 12:22:38.000000000 +0000
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -383,7 +383,7 @@ void os::init_system_properties_values()
 #ifdef __APPLE__
   #define DEFAULT_LIBPATH "/lib:/usr/lib"
 #elif defined(__NetBSD__)
-  #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+  #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:@PREFIX@/lib:/lib:/usr/lib"
 #else
   #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
 #endif
@@ -3357,7 +3357,11 @@ void os::Bsd::check_signal_handler(int s
   struct sigaction act;
   if (os_sigaction == NULL) {
     // only trust the default sigaction, in case it has been interposed
+#if defined(__NetBSD__)
+    os_sigaction = (os_sigaction_t)dlsym(RTLD_DEFAULT, "__sigaction14");
+#else
     os_sigaction = (os_sigaction_t)dlsym(RTLD_DEFAULT, "sigaction");
+#endif
     if (os_sigaction == NULL) return;
   }
 

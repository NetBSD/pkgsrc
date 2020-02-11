$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.3 2020/02/11 02:30:42 ryoon Exp $

sigaction part: https://github.com/battleblow/openjdk-jdk11u/pull/97
Last chunk: https://github.com/battleblow/openjdk-jdk11u/pull/96

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2020-01-15 18:29:57.000000000 +0000
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -379,7 +379,7 @@ void os::init_system_properties_values()
 #ifdef __APPLE__
   #define DEFAULT_LIBPATH "/lib:/usr/lib"
 #elif defined(__NetBSD__)
-  #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+  #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:@PREFIX@/lib:/lib:/usr/lib"
 #else
   #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
 #endif
@@ -3377,7 +3377,11 @@ void os::Bsd::check_signal_handler(int s
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
 
@@ -3632,7 +3636,7 @@ void os::set_native_thread_name(const ch
 #elif defined(__FreeBSD__) || defined(__OpenBSD__)
     pthread_set_name_np(pthread_self(), name);
 #elif defined(__NetBSD__)
-    pthread_setname_np(pthread_self(), "%s", name);
+    pthread_setname_np(pthread_self(), "%s", const_cast<char *>(name));
 #endif
   }
 }

$NetBSD: patch-src_hotspot_os_bsd_os__bsd.cpp,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/hotspot/os/bsd/os_bsd.cpp.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/hotspot/os/bsd/os_bsd.cpp
@@ -106,6 +106,11 @@
   #include <vm/vm_param.h>
 #endif
 
+#ifdef __NetBSD__
+#include <link_elf.h>
+#include <lwp.h>
+#endif
+
 #ifdef __OpenBSD__
   #include <pthread_np.h>
   #include <link_elf.h>
@@ -381,7 +386,7 @@ void os::init_system_properties_values()
     #ifdef __APPLE__
       #define DEFAULT_LIBPATH "/lib:/usr/lib"
     #elif defined(__NetBSD__)
-      #define DEFAULT_LIBPATH "/usr/lib:/usr/pkg/lib"
+      #define DEFAULT_LIBPATH "@PREFIX@/lib/jni:/usr/pkg/lib:/lib:/usr/lib"
     #else
       #define DEFAULT_LIBPATH "/usr/lib:/usr/local/lib"
     #endif
@@ -2318,7 +2323,7 @@ void os::set_native_thread_name(const ch
 #elif defined(__FreeBSD__) || defined(__OpenBSD__)
     pthread_set_name_np(pthread_self(), name);
 #elif defined(__NetBSD__)
-    pthread_setname_np(pthread_self(), "%s", name);
+    pthread_setname_np(pthread_self(), "%s", const_cast<char *>(name));
 #endif
   }
 }

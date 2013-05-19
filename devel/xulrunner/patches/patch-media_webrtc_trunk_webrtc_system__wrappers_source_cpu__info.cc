$NetBSD: patch-media_webrtc_trunk_webrtc_system__wrappers_source_cpu__info.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/system_wrappers/source/cpu_info.cc.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/trunk/webrtc/system_wrappers/source/cpu_info.cc
@@ -12,13 +12,15 @@
 
 #if defined(_WIN32)
 #include <Windows.h>
-#elif defined(WEBRTC_MAC)
-#include <sys/sysctl.h>
+#elif defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #elif defined(WEBRTC_ANDROID)
 // Not implemented yet, might be possible to use Linux implementation
-#else // defined(WEBRTC_LINUX)
+#elif defined(WEBRTC_LINUX)
 #include <sys/sysinfo.h>
+#else // defined(_SC_NPROCESSORS_ONLN)
+#include <unistd.h>
 #endif
 
 #include "trace.h"
@@ -41,8 +43,15 @@ WebRtc_UWord32 CpuInfo::DetectNumberOfCo
     WEBRTC_TRACE(kTraceStateInfo, kTraceUtility, -1,
                  "Available number of cores:%d", number_of_cores_);
 
-#elif defined(WEBRTC_MAC)
-    int name[] = {CTL_HW, HW_AVAILCPU};
+#elif defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
+    int name[] = {
+      CTL_HW,
+#ifdef HW_AVAILCPU
+      HW_AVAILCPU,
+#else
+      HW_NCPU,
+#endif
+    };
     int ncpu;
     size_t size = sizeof(ncpu);
     if (0 == sysctl(name, 2, &ncpu, &size, NULL, 0)) {
@@ -54,6 +63,8 @@ WebRtc_UWord32 CpuInfo::DetectNumberOfCo
                    "Failed to get number of cores");
       number_of_cores_ = 1;
     }
+#elif defined(_SC_NPROCESSORS_ONLN)
+    _numberOfCores = sysconf(_SC_NPROCESSORS_ONLN);
 #else
     WEBRTC_TRACE(kTraceWarning, kTraceUtility, -1,
                  "No function to get number of cores");

$NetBSD: patch-mozilla_gfx_skia_skia_src_core_SkUtilsArm.cpp,v 1.1 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/gfx/skia/skia/src/core/SkUtilsArm.cpp.orig	2016-04-07 21:33:15.000000000 +0000
+++ mozilla/gfx/skia/skia/src/core/SkUtilsArm.cpp
@@ -16,6 +16,10 @@
 #include <string.h>
 #include <pthread.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 // Set USE_ANDROID_NDK_CPU_FEATURES to use the Android NDK's
 // cpu-features helper library to detect NEON at runtime. See
 // http://crbug.com/164154 to see why this is needed in Chromium
@@ -47,6 +51,11 @@
 #  endif
 #endif
 
+#if !defined(TEMP_FAILURE_RETRY)
+   // TEMP_FAILURE_RETRY is glibc specific
+#  define TEMP_FAILURE_RETRY
+#endif
+
 // A function used to determine at runtime if the target CPU supports
 // the ARM NEON instruction set. This implementation is Linux-specific.
 static bool sk_cpu_arm_check_neon(void) {
@@ -82,6 +91,17 @@ static bool sk_cpu_arm_check_neon(void) 
 
   result = (android_getCpuFeatures() & ANDROID_CPU_ARM_FEATURE_NEON) != 0;
 
+#elif defined(__NetBSD__)
+
+    size_t len;
+    int flag;
+    len = sizeof(flag);
+    if (sysctlbyname("machdep.neon_present", &flag, &len, NULL, 0) == 0) {
+        result = flag != 0;
+    } else {
+        result = false;
+    }
+
 #else  // USE_ANDROID_NDK_CPU_FEATURES
 
     // There is no user-accessible CPUID instruction on ARM that we can use.

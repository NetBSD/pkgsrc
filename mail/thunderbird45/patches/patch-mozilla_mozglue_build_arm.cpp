$NetBSD: patch-mozilla_mozglue_build_arm.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/mozglue/build/arm.cpp.orig	2016-04-07 21:33:29.000000000 +0000
+++ mozilla/mozglue/build/arm.cpp
@@ -102,10 +102,13 @@ check_neon(void)
 }
 #    endif // !MOZILLA_PRESUME_NEON
 
-#  elif defined(__linux__) || defined(ANDROID)
+#  elif defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    include <stdio.h>
 #    include <stdlib.h>
 #    include <string.h>
+#    if defined(__NetBSD__)
+#      include <sys/sysctl.h>
+#    endif
 
 enum{
   MOZILLA_HAS_EDSP_FLAG=1,
@@ -114,6 +117,29 @@ enum{
   MOZILLA_HAS_NEON_FLAG=8
 };
 
+#    if defined(__NetBSD__)
+static unsigned
+get_arm_cpu_flags(void)
+{
+  unsigned flags = 0;
+  size_t len;
+  int flag;
+
+  len = sizeof(flag);
+  if (sysctlbyname("machdep.simdex_present", &flag, &len, NULL, 0) == 0 && flag) {
+    flags |= MOZILLA_HAS_ARMV6_FLAG;
+    flags |= MOZILLA_HAS_EDSP_FLAG;
+  }
+
+  len = sizeof(flag);
+  if (sysctlbyname("machdep.neon_present", &flag, &len, NULL, 0) == 0 && flag) {
+    flags |= MOZILLA_HAS_ARMV7_FLAG;
+    flags |= MOZILLA_HAS_NEON_FLAG;
+  }
+
+  return flags;
+}
+#    else
 static unsigned
 get_arm_cpu_flags(void)
 {
@@ -178,6 +204,7 @@ get_arm_cpu_flags(void)
   }
   return flags;
 }
+#    endif
 
 // Cache a local copy so we only have to read /proc/cpuinfo once.
 static unsigned arm_cpu_flags = get_arm_cpu_flags();

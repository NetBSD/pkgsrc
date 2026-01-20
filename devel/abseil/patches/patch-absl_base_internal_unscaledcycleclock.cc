$NetBSD: patch-absl_base_internal_unscaledcycleclock.cc,v 1.1 2026/01/20 00:33:18 jmcneill Exp $

Add UnscaledCycleClock::Frequency() implementation for NetBSD/powerpc.

--- absl/base/internal/unscaledcycleclock.cc.orig	2026-01-18 16:50:32.243350302 +0000
+++ absl/base/internal/unscaledcycleclock.cc
@@ -23,7 +23,7 @@
 #if defined(__powerpc__) || defined(__ppc__)
 #ifdef __GLIBC__
 #include <sys/platform/ppc.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 // clang-format off
 // This order does actually matter =(.
 #include <sys/types.h>
@@ -102,6 +102,15 @@ double UnscaledCycleClock::Frequency() {
                  &length, nullptr, 0);
   });
   return timebase_frequency;
+#elif defined(__NetBSD__)
+  static once_flag init_timebase_frequency_once;
+  static int timebase_frequency = 0;
+  base_internal::LowLevelCallOnce(&init_timebase_frequency_once, [&]() {
+    size_t length = sizeof(timebase_frequency);
+    sysctlbyname("machdep.timebase", &timebase_frequency,
+                 &length, nullptr, 0);
+  });
+  return static_cast<double>(timebase_frequency);
 #else
 #error Must implement UnscaledCycleClock::Frequency()
 #endif

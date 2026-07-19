$NetBSD: patch-gcc_config_aarch64_driver-aarch64.cc,v 1.1 2026/07/19 11:17:43 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/config/aarch64/driver-aarch64.cc.orig	2026-06-12 06:09:06.122518264 +0000
+++ gcc/config/aarch64/driver-aarch64.cc
@@ -28,6 +28,76 @@
 #include "aarch64-protos.h"
 #include "aarch64-feature-deps.h"

+
+/* Default architecture to use if -mcpu=native did not detect a known CPU.  */
+#if TARGET_MACHO
+#define DEFAULT_ARCH "apple-m1"
+#else
+#define DEFAULT_ARCH "8A"
+#define DEFAULT_CPU "generic-armv8-a"
+#endif
+
+
+#if defined(__APPLE__)
+/* macOS does not have /proc/cpuinfo and needs a different approach,
+   based on sysctl.  It is much simpler.  */
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+const char *
+host_detect_local_cpu (ATTRIBUTE_UNUSED int argc, ATTRIBUTE_UNUSED const char **argv)
+{
+  bool arch = false;
+  bool tune = false;
+  bool cpu = false;
+  const char *res = NULL;
+  uint32_t family;
+  size_t len = sizeof(family);
+
+  gcc_assert (argc);
+  if (!argv[0])
+    return NULL;
+
+  /* Are we processing -march, mtune or mcpu?  */
+  arch = strcmp (argv[0], "arch") == 0;
+  if (!arch)
+    tune = strcmp (argv[0], "tune") == 0;
+  if (!arch && !tune)
+    cpu = strcmp (argv[0], "cpu") == 0;
+  if (!arch && !tune && !cpu)
+    return NULL;
+
+  sysctlbyname("hw.cpufamily", &family, &len, NULL, 0);
+
+  switch (family)
+  {
+    case 0x07d34b9f: // Vortex, Tempest
+      res = "apple-a12";
+      break;
+    case 0x573b5eec:
+    case 0x1b588bb3: // Firestorm, Icestorm
+      res = "apple-m1";
+      break;
+    case 0xda33d83d: // Blizzard, Avalanche
+      res = "apple-m2";
+      break;
+    case 0xfa33415e: // Ibiza (M3)
+    case 0x5f4dea93: // Lobos (M3 Pro)
+    case 0x72015832: // Palma (M3 Max)
+      res = "apple-m3";
+      break;
+    default:
+      res = DEFAULT_ARCH;
+  }
+
+  if (res)
+    return concat ("-m", argv[0], "=", res, NULL);
+  else
+    return NULL;
+}
+
+#else
+
 struct aarch64_arch_extension
 {
   const char *ext;
@@ -58,9 +128,6 @@ struct aarch64_core_data
 #define INVALID_IMP ((unsigned char) -1)
 #define INVALID_CORE ((unsigned)-1)
 #define ALL_VARIANTS ((unsigned)-1)
-/* Default architecture to use if -mcpu=native did not detect a known CPU.  */
-#define DEFAULT_ARCH "8A"
-#define DEFAULT_CPU "generic-armv8-a"

 #define AARCH64_CORE(CORE_NAME, CORE_IDENT, SCHED, ARCH, FLAGS, COSTS, IMP, PART, VARIANT) \
   { CORE_NAME, #ARCH, IMP, PART, VARIANT, feature_deps::cpu_##CORE_IDENT },
@@ -504,3 +571,4 @@ not_found:
     return NULL;
   }
 }
+#endif

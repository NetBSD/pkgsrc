$NetBSD: patch-gcc_config_aarch64_driver-aarch64.cc,v 1.1 2025/02/05 16:30:35 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/config/aarch64/driver-aarch64.cc
+++ gcc/config/aarch64/driver-aarch64.cc
@@ -28,6 +28,74 @@
 #include "aarch64-protos.h"
 #include "aarch64-feature-deps.h"

+#if TARGET_MACHO
+# include <sys/types.h>
+# include <sys/sysctl.h>
+#endif
+
+
+#if TARGET_MACHO
+
+/* Default architecture to use if -mcpu=native did not detect a known CPU.  */
+#define DEFAULT_ARCH "apple-m1"
+
+/* macOS does not have /proc/cpuinfo and needs a different approach,
+   based on sysctl.  It is much simpler.  */
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
@@ -477,3 +545,4 @@ not_found:
   }
 }

+#endif

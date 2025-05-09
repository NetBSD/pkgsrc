$NetBSD: patch-lib_CL_pocl__llvm__utils.cc,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- lib/CL/pocl_llvm_utils.cc.orig	2025-05-03 06:22:51.273436819 +0000
+++ lib/CL/pocl_llvm_utils.cc
@@ -257,11 +257,17 @@ const char *pocl_get_distro_kernellib_va
   StringMap<bool> Features;

 #if defined(__i386__) || defined(__x86_64__)
+
+#if LLVM_MAJOR < 19
   if (!llvm::sys::getHostCPUFeatures(Features)) {
     POCL_MSG_WARN("LLVM can't get host CPU flags!\n");
     return NULL;
   }
 #else
+  Features = llvm::sys::getHostCPUFeatures();
+#endif
+
+#else
   return pocl_get_llvm_cpu_name();
 #endif

@@ -295,11 +301,16 @@ const char *pocl_get_distro_cpu_name(con
   StringMap<bool> Features;

 #if defined(__i386__) || defined(__x86_64__)
+#if LLVM_MAJOR < 19
   if (!llvm::sys::getHostCPUFeatures(Features)) {
     POCL_MSG_WARN("LLVM can't get host CPU flags!\n");
     return NULL;
   }
 #else
+   Features = llvm::sys::getHostCPUFeatures();
+ #endif
+
+#else
   return pocl_get_llvm_cpu_name();
 #endif

@@ -327,24 +338,35 @@ int pocl_bitcode_is_triple(const char *b
 // TODO this should be fixed to not require LLVM eventually,
 // so that LLVM-less builds also report FMA correctly.
 int cpu_has_fma() {
-  StringMap<bool> features;
-  bool res = llvm::sys::getHostCPUFeatures(features);
-  return ((res && (features["fma"] || features["fma4"])) ? 1 : 0);
+  StringMap<bool> Features;
+#if LLVM_MAJOR < 19
+  bool Res = llvm::sys::getHostCPUFeatures(Features);
+#else
+  const bool Res = true;
+  Features = llvm::sys::getHostCPUFeatures();
+#endif
+  return ((Res && (Features["fma"] || Features["fma4"])) ? 1 : 0);
 }

 #define VECWIDTH(x)                                                            \
   std::min(std::max((lane_width / (unsigned)(sizeof(x))), 1U), 16U)

 void cpu_setup_vector_widths(cl_device_id dev) {
-  StringMap<bool> features;
-  bool res = llvm::sys::getHostCPUFeatures(features);
+  StringMap<bool> Features;
+  bool Res = true;
+#if LLVM_MAJOR < 19
+  Res = llvm::sys::getHostCPUFeatures(Features);
+#else
+  Features = llvm::sys::getHostCPUFeatures();
+#endif
+
   unsigned lane_width = 1;
-  if (res) {
-    if ((features["sse"]) || (features["neon"]))
+  if (Res) {
+    if ((Features["sse"]) || (Features["neon"]))
       lane_width = 16;
-    if (features["avx"])
+    if (Features["avx"])
       lane_width = 32;
-    if (features["avx512f"])
+    if (Features["avx512f"])
       lane_width = 64;
   }
   dev->native_vector_width_in_bits = lane_width * 8;

$NetBSD: patch-deps_v8_src_base_platform_platform-openbsd.cc,v 1.1 2019/12/09 20:05:40 adam Exp $

Add support for NetBSD/arm.

--- deps/v8/src/base/platform/platform-openbsd.cc.orig	2017-09-26 21:14:30.000000000 +0000
+++ deps/v8/src/base/platform/platform-openbsd.cc
@@ -34,6 +34,48 @@
 namespace v8 {
 namespace base {
 
+#ifdef __arm__
+
+bool OS::ArmUsingHardFloat() {
+  // GCC versions 4.6 and above define __ARM_PCS or __ARM_PCS_VFP to specify
+  // the Floating Point ABI used (PCS stands for Procedure Call Standard).
+  // We use these as well as a couple of other defines to statically determine
+  // what FP ABI used.
+  // GCC versions 4.4 and below don't support hard-fp.
+  // GCC versions 4.5 may support hard-fp without defining __ARM_PCS or
+  // __ARM_PCS_VFP.
+
+#define GCC_VERSION (__GNUC__ * 10000                                          \
+                     + __GNUC_MINOR__ * 100                                    \
+                     + __GNUC_PATCHLEVEL__)
+#if GCC_VERSION >= 40600
+#if defined(__ARM_PCS_VFP)
+  return true;
+#else
+  return false;
+#endif
+
+#elif GCC_VERSION < 40500
+  return false;
+
+#else
+#if defined(__ARM_PCS_VFP)
+  return true;
+#elif defined(__ARM_PCS) || defined(__SOFTFP__) || defined(__SOFTFP) || \
+      !defined(__VFP_FP__)
+  return false;
+#else
+#error "Your version of GCC does not report the FP ABI compiled for."          \
+       "Please report it on this issue"                                        \
+       "http://code.google.com/p/v8/issues/detail?id=2140"
+
+#endif
+#endif
+#undef GCC_VERSION
+}
+
+#endif  // def __arm__
+
 TimezoneCache* OS::CreateTimezoneCache() {
   return new PosixDefaultTimezoneCache();
 }

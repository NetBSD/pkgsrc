$NetBSD: patch-third__party_abseil-cpp_absl_base_config.h,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* Support NetBSD.

--- third_party/abseil-cpp/absl/base/config.h.orig	2021-02-15 05:04:34.000000000 +0000
+++ third_party/abseil-cpp/absl/base/config.h
@@ -364,7 +364,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||   \
     defined(__ros__) || defined(__native_client__) || defined(__asmjs__) || \
     defined(__wasm__) || defined(__Fuchsia__) || defined(__sun) || \
-    defined(__ASYLO__)
+    defined(__ASYLO__) || defined(__NetBSD__)
 #define ABSL_HAVE_MMAP 1
 #endif
 

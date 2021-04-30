$NetBSD: patch-absl_base_config.h,v 1.2 2021/04/30 10:32:17 adam Exp $

Add support for NetBSD.

--- absl/base/config.h.orig	2021-04-20 16:55:14.000000000 +0000
+++ absl/base/config.h
@@ -370,6 +370,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||   \
+    defined(__NetBSD__) || \
     defined(__ros__) || defined(__native_client__) || defined(__asmjs__) || \
     defined(__wasm__) || defined(__Fuchsia__) || defined(__sun) || \
     defined(__ASYLO__) || defined(__myriad2__)
@@ -383,6 +384,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
     defined(__ros__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif

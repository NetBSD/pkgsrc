$NetBSD: patch-absl_base_config.h,v 1.4 2022/03/06 09:34:06 wiz Exp $

Add support for NetBSD.
https://github.com/abseil/abseil-cpp/pull/1121

--- absl/base/config.h.orig	2021-11-03 15:26:14.000000000 +0000
+++ absl/base/config.h
@@ -411,6 +411,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||    \
     defined(__asmjs__) || defined(__wasm__) || defined(__Fuchsia__) ||    \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||       \
@@ -425,6 +426,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || \
     defined(_AIX) || defined(__ros__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif

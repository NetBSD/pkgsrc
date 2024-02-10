$NetBSD: patch-third__party_abseil-cpp_absl_base_internal_raw__logging.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2023-12-13 09:40:20.988739236 +0000
+++ third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -39,7 +39,8 @@
 // this, consider moving both to config.h instead.
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
     defined(__Fuchsia__) || defined(__native_client__) ||               \
-    defined(__OpenBSD__) || defined(__EMSCRIPTEN__) || defined(__ASYLO__)
+    defined(__OpenBSD__) || defined(__EMSCRIPTEN__) || defined(__ASYLO__) || \
+    defined(__NetBSD__)
 
 #include <unistd.h>
 

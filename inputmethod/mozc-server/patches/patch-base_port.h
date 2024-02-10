$NetBSD: patch-base_port.h,v 1.6 2024/02/10 01:17:27 ryoon Exp $

--- base/port.h.orig	2023-10-26 12:00:50.000000000 +0000
+++ base/port.h
@@ -45,6 +45,7 @@ enum class PlatformType {
   kIPhone,    // Darwin-based firmware, devices, or simulator
   kWASM,      // WASM
   kChromeOS,  // ChromeOS
+  kNetBSD,    // NetBSD
 };
 
 // kTargetPlatform is the current build target platform.
@@ -68,6 +69,8 @@ inline constexpr PlatformType kTargetPla
 #endif                   // !TARGET_OS_IPHONE
 #elif defined(__wasm__)  // __APPLE__
 inline constexpr PlatformType kTargetPlatform = PlatformType::kWASM;
+#elif defined(__NetBSD__)
+inline constexpr PlatformType kTargetPlatform = PlatformType::kNetBSD;
 #else                    // __wasm__
 #error "Unsupported target platform."
 #endif  // !__wasm__

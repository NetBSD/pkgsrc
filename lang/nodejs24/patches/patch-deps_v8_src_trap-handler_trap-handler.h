$NetBSD: patch-deps_v8_src_trap-handler_trap-handler.h,v 1.1 2026/11/22 14:36:14 kikadf Exp $

* Add trap-handler support for Open- and NetBSD on x64

--- deps/v8/src/trap-handler/trap-handler.h.orig	2026-10-27 23:43:43.000000000 +0000
+++ deps/v8/src/trap-handler/trap-handler.h
@@ -15,10 +15,10 @@
 
 namespace v8::internal::trap_handler {
 
-// X64 on Linux, Windows, MacOS, FreeBSD.
+// X64 on Linux, Windows, MacOS, FreeBSD, OpenBSD, NetBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
-     V8_OS_FREEBSD)
+     V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 (non-simulator) on Linux, Windows, MacOS.
 #elif V8_TARGET_ARCH_ARM64 && V8_HOST_ARCH_ARM64 && \

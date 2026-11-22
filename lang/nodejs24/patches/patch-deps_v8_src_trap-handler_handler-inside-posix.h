$NetBSD: patch-deps_v8_src_trap-handler_handler-inside-posix.h,v 1.1 2026/11/22 14:36:14 kikadf Exp $

* Add trap-handler support for Open- and NetBSD on x64

--- deps/v8/src/trap-handler/handler-inside-posix.h.orig	2026-10-27 23:43:43.000000000 +0000
+++ deps/v8/src/trap-handler/handler-inside-posix.h
@@ -13,12 +13,12 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
 #else
-#error Posix trap handlers are only supported on Linux, MacOSX and FreeBSD.
+#error Posix trap handlers are only supported on Linux, MacOSX, FreeBSD, OpenBSD and NetBSD.
 #endif
 
 void HandleSignal(int signum, siginfo_t* info, void* context);

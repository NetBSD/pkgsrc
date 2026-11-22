$NetBSD: patch-deps_v8_src_api_api.cc,v 1.1 2026/11/22 14:36:14 kikadf Exp $

* Add trap-handler support for Open- and NetBSD on x64

--- deps/v8/src/api/api.cc.orig	2026-10-27 23:43:42.000000000 +0000
+++ deps/v8/src/api/api.cc
@@ -154,7 +154,7 @@
 #include "src/wasm/wasm-serialization.h"
 #endif  // V8_ENABLE_WEBASSEMBLY
 
-#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 #include <signal.h>
 #include <unistd.h>
 
@@ -163,7 +163,7 @@
 #include "src/trap-handler/handler-inside-posix.h"
 #endif  // V8_ENABLE_WEBASSEMBLY
 
-#endif  // V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#endif  // V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 
 #if V8_OS_WIN
 #include "include/v8-wasm-trap-handler-win.h"
@@ -6484,7 +6484,7 @@ bool v8::V8::Initialize(const int build_
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_NETBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED

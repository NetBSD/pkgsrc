$NetBSD: patch-deps_v8_src_api_api.cc,v 1.1 2026/11/22 14:33:45 kikadf Exp $

* Add trap-handler support for Open- and NetBSD on x64

--- deps/v8/src/api/api.cc.orig	2026-11-11 00:20:16.000000000 +0000
+++ deps/v8/src/api/api.cc
@@ -164,7 +164,7 @@
 
 #include "src/strings/string-hasher-inl.h"
 
-#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 #include <signal.h>
 #include <unistd.h>
 
@@ -173,7 +173,7 @@
 #include "src/trap-handler/handler-inside-posix.h"
 #endif  // V8_ENABLE_WEBASSEMBLY
 
-#endif  // V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#endif  // V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD || V8_OS_NETBSD
 
 #if V8_OS_WIN
 #include "include/v8-wasm-trap-handler-win.h"
@@ -6371,7 +6371,7 @@ bool v8::V8::Initialize(const int build_
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_NETBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED

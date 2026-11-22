$NetBSD: patch-src_node.cc,v 1.3 2026/11/22 14:33:45 kikadf Exp $

* Add trap-handler support for Free-, Open- and NetBSD on x64

--- src/node.cc.orig	2026-11-11 00:20:19.000000000 +0000
+++ src/node.cc
@@ -84,7 +84,7 @@
 #include "../deps/v8/third_party/vtune/v8-vtune.h"
 #endif
 
-#if defined(__APPLE__) || defined(__linux__) || defined(_WIN32)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(_WIN32)
 #define NODE_USE_V8_WASM_TRAP_HANDLER 1
 #else
 #define NODE_USE_V8_WASM_TRAP_HANDLER 0

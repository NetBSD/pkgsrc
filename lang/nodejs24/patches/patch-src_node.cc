$NetBSD: patch-src_node.cc,v 1.1 2026/11/22 14:36:14 kikadf Exp $

* Add trap-handler support for Free-, Open- and NetBSD on x64

--- src/node.cc.orig	2026-11-15 15:08:12.522523229 +0000
+++ src/node.cc
@@ -83,7 +83,7 @@
 
 #include "large_pages/node_large_page.h"
 
-#if defined(__APPLE__) || defined(__linux__) || defined(_WIN32)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(_WIN32)
 #define NODE_USE_V8_WASM_TRAP_HANDLER 1
 #else
 #define NODE_USE_V8_WASM_TRAP_HANDLER 0

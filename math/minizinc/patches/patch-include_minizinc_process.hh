$NetBSD: patch-include_minizinc_process.hh,v 1.1 2026/11/17 01:10:16 alnsn Exp $

Declare environ on NetBSD.

--- include/minizinc/process.hh.orig	2026-11-17 00:56:45.031658875 +0000
+++ include/minizinc/process.hh
@@ -39,6 +39,10 @@
 #include <thread>
 #include <vector>
 
+#if defined(__NetBSD__)
+extern "C" char** environ;
+#endif
+
 namespace MiniZinc {
 
 #if !defined(_WIN32) && !defined(__EMSCRIPTEN__)

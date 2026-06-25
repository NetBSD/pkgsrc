$NetBSD: patch-lib_qa__utils.cc,v 1.1 2026/06/25 07:32:24 wiz Exp $

Fix build with fmtlib 12.2.0.
https://github.com/gnuradio/volk/issues/868

--- lib/qa_utils.cc.orig	2026-06-25 07:29:56.366917249 +0000
+++ lib/qa_utils.cc
@@ -28,7 +28,7 @@
 #include <random>
 #include <vector> // for vector, _Bit_refe...
 
-#include <fmt/core.h>
+#include <fmt/format.h>
 
 // Warmup time for CPU frequency scaling (ms)
 static double g_warmup_ms = 2000.0;

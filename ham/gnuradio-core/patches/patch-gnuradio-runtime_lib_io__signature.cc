$NetBSD: patch-gnuradio-runtime_lib_io__signature.cc,v 1.1 2024/08/18 11:50:39 tnn Exp $

fix build w/ fmtlib 11
https://github.com/gnuradio/gnuradio/commit/19b070051c1c2b5fb6f2da8fb6422b27418c3dfa.patch

--- gnuradio-runtime/lib/io_signature.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gnuradio-runtime/lib/io_signature.cc
@@ -16,6 +16,11 @@
 #include <spdlog/tweakme.h>
 
 #include <spdlog/fmt/fmt.h>
+#if __has_include(<spdlog/fmt/ranges.h>)
+#include <spdlog/fmt/ranges.h>
+#elif __has_include(<spdlog/fmt/bundled/ranges.h>)
+#include <spdlog/fmt/bundled/ranges.h>
+#endif
 #include <string_view>
 #include <algorithm>
 #include <memory>

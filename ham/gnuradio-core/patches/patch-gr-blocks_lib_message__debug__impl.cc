$NetBSD: patch-gr-blocks_lib_message__debug__impl.cc,v 1.3 2024/08/18 11:50:39 tnn Exp $

fix build w/ fmtlib 11
https://github.com/gnuradio/gnuradio/commit/19b070051c1c2b5fb6f2da8fb6422b27418c3dfa.patch

--- gr-blocks/lib/message_debug_impl.cc.orig	2024-01-17 20:36:19.000000000 +0000
+++ gr-blocks/lib/message_debug_impl.cc
@@ -19,6 +19,11 @@
 #include <pmt/pmt.h>
 #include <spdlog/common.h>
 #include <spdlog/fmt/fmt.h>
+#if __has_include(<spdlog/fmt/ranges.h>)
+#include <spdlog/fmt/ranges.h>
+#elif __has_include(<spdlog/fmt/bundled/ranges.h>)
+#include <spdlog/fmt/bundled/ranges.h>
+#endif
 #include <functional>
 #include <utility>
 #include <vector>

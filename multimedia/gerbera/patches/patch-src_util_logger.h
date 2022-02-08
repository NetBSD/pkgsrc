$NetBSD: patch-src_util_logger.h,v 1.1 2022/02/08 06:26:49 khorben Exp $

Fix for fmt > 8.0

From https://github.com/gerbera/gerbera/commit/82d84ac5e62c23e717198fc7b2ef190ff95e70d1

--- src/util/logger.h.orig	2021-09-30 19:23:27.000000000 +0000
+++ src/util/logger.h
@@ -32,7 +32,9 @@
 #ifndef __LOGGER_H__
 #define __LOGGER_H__
 
+#include <fmt/format.h>
 #include <spdlog/spdlog.h>
+#include <type_traits>
 
 #define log_debug SPDLOG_DEBUG
 #define log_info SPDLOG_INFO
@@ -40,4 +42,17 @@
 #define log_error SPDLOG_ERROR
 #define log_js SPDLOG_INFO
 
+#if FMT_VERSION >= 80100
+template <typename T>
+struct fmt::formatter<T, std::enable_if_t<std::is_enum_v<T>, char>>
+    : formatter<std::underlying_type_t<T>> {
+    template <typename FormatContext>
+    auto format(const T& value, FormatContext& ctx) -> decltype(ctx.out())
+    {
+        return fmt::formatter<std::underlying_type_t<T>>::format(
+            static_cast<std::underlying_type_t<T>>(value), ctx);
+    }
+};
+#endif
+
 #endif // __LOGGER_H__

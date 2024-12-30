$NetBSD: patch-include_spdlog_common.h,v 1.3 2024/12/30 02:08:56 ryoon Exp $

From: Upstream 276ee5f5c0eb13626bd367b006ace5eae9526d8a

--- include/spdlog/common.h.orig	2024-11-09 15:01:30.000000000 +0000
+++ include/spdlog/common.h
@@ -365,10 +365,17 @@ SPDLOG_CONSTEXPR_FUNC spdlog::wstring_vi
 #endif
 
 #ifndef SPDLOG_USE_STD_FORMAT
+#if FMT_VERSION >= 110100
+template <typename T, typename... Args>
+inline fmt::basic_string_view<T> to_string_view(fmt::basic_format_arg<T> fmt) {
+    return fmt;
+}
+#else
 template <typename T, typename... Args>
 inline fmt::basic_string_view<T> to_string_view(fmt::basic_format_string<T, Args...> fmt) {
     return fmt;
 }
+#endif
 #elif __cpp_lib_format >= 202207L
 template <typename T, typename... Args>
 SPDLOG_CONSTEXPR_FUNC std::basic_string_view<T> to_string_view(

$NetBSD: patch-include_spdlog_common.h,v 1.1 2023/05/17 08:20:06 wiz Exp $

Fix build with newer fmtlib.
https://github.com/gabime/spdlog/commit/0ca574ae168820da0268b3ec7607ca7b33024d05

--- include/spdlog/common.h.orig	2022-11-02 21:13:08.000000000 +0000
+++ include/spdlog/common.h
@@ -160,12 +160,19 @@ using format_string_t = fmt::format_stri
 template<class T>
 using remove_cvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
 
+template <typename Char>
+#if FMT_VERSION >= 90101
+using fmt_runtime_string = fmt::runtime_format_string<Char>;
+#else
+using fmt_runtime_string = fmt::basic_runtime<Char>;
+#endif
+
 // clang doesn't like SFINAE disabled constructor in std::is_convertible<> so have to repeat the condition from basic_format_string here,
 // in addition, fmt::basic_runtime<Char> is only convertible to basic_format_string<Char> but not basic_string_view<Char>
 template<class T, class Char = char>
 struct is_convertible_to_basic_format_string
     : std::integral_constant<bool,
-          std::is_convertible<T, fmt::basic_string_view<Char>>::value || std::is_same<remove_cvref_t<T>, fmt::basic_runtime<Char>>::value>
+          std::is_convertible<T, fmt::basic_string_view<Char>>::value || std::is_same<remove_cvref_t<T>, fmt_runtime_string<Char>>::value>
 {};
 
 #    if defined(SPDLOG_WCHAR_FILENAMES) || defined(SPDLOG_WCHAR_TO_UTF8_SUPPORT)

$NetBSD: patch-include_nlohmann_detail_conversions_from__json.hpp,v 1.1 2025/04/27 20:07:25 wiz Exp $

https://github.com/nlohmann/json/pull/4736
https://github.com/nlohmann/json/pull/4763

--- include/nlohmann/detail/conversions/from_json.hpp.orig	2025-04-11 08:42:28.000000000 +0000
+++ include/nlohmann/detail/conversions/from_json.hpp
@@ -32,6 +32,10 @@
 #include <nlohmann/detail/string_concat.hpp>
 #include <nlohmann/detail/value_t.hpp>
 
+#if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
+    #include <string_view> // u8string_view
+#endif
+
 NLOHMANN_JSON_NAMESPACE_BEGIN
 namespace detail
 {
@@ -540,7 +544,10 @@ inline void from_json(const BasicJsonTyp
         JSON_THROW(type_error::create(302, concat("type must be string, but is ", j.type_name()), &j));
     }
     const auto& s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
-#ifdef JSON_HAS_CPP_20
+    // Checking for C++20 standard or later can be insufficient in case the
+    // library support for char8_t is either incomplete or was disabled
+    // altogether. Use the __cpp_lib_char8_t feature test instead.
+#if defined(__cpp_lib_char8_t) && (__cpp_lib_char8_t >= 201907L)
     p = std_fs::path(std::u8string_view(reinterpret_cast<const char8_t*>(s.data()), s.size()));
 #else
     p = std_fs::u8path(s); // accepts UTF-8 encoded std::string in C++17, deprecated in C++20

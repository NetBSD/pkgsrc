$NetBSD: patch-single__include_nlohmann_json.hpp,v 1.1 2025/04/27 20:07:25 wiz Exp $

https://github.com/nlohmann/json/pull/4736
https://github.com/nlohmann/json/pull/4763

--- single_include/nlohmann/json.hpp.orig	2025-04-11 08:42:28.000000000 +0000
+++ single_include/nlohmann/json.hpp
@@ -4497,6 +4497,10 @@ NLOHMANN_JSON_NAMESPACE_END
     #pragma clang diagnostic ignored "-Wweak-vtables"
 #endif
 
+#if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
+    #include <string_view> // u8string_view
+#endif
+
 NLOHMANN_JSON_NAMESPACE_BEGIN
 namespace detail
 {
@@ -5325,7 +5329,10 @@ inline void from_json(const BasicJsonTyp
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
@@ -5380,7 +5387,8 @@ NLOHMANN_JSON_NAMESPACE_END
 
 #include <algorithm> // copy
 #include <iterator> // begin, end
-#include <string> // string
+#include <memory> // allocator_traits
+#include <string> //  basic_string, char_traits
 #include <tuple> // tuple, get
 #include <type_traits> // is_same, is_constructible, is_floating_point, is_enum, underlying_type
 #include <utility> // move, forward, declval, pair
@@ -6087,15 +6095,21 @@ inline void to_json(BasicJsonType& j, co
 }
 
 #if JSON_HAS_FILESYSTEM || JSON_HAS_EXPERIMENTAL_FILESYSTEM
+#if defined(__cpp_lib_char8_t)
+template<typename BasicJsonType, typename Tr, typename Allocator>
+inline void to_json(BasicJsonType& j, const std::basic_string<char8_t, Tr, Allocator>& s)
+{
+    using OtherAllocator = typename std::allocator_traits<Allocator>::template rebind_alloc<char>;
+    j = std::basic_string<char, std::char_traits<char>, OtherAllocator>(s.begin(), s.end(), s.get_allocator());
+}
+#endif
+
 template<typename BasicJsonType>
 inline void to_json(BasicJsonType& j, const std_fs::path& p)
 {
-#ifdef JSON_HAS_CPP_20
-    const std::u8string s = p.u8string();
-    j = std::string(s.begin(), s.end());
-#else
-    j = p.u8string(); // returns std::string in C++17
-#endif
+    // Returns either a std::string or a std::u8string depending whether library
+    // support for char8_t is enabled.
+    j = p.u8string();
 }
 #endif
 

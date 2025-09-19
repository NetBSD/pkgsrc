$NetBSD: patch-absl_log_internal_check__op.h,v 1.1 2025/09/19 06:56:57 prlw1 Exp $

Fix check_op(s) compilation failures on gcc 8 which eagerly
tries to instantiate std::underlying_type for non-num types.

Before cpp20 using std::underlying_t on non enum types is undefined behaviour.

https://github.com/abseil/abseil-cpp/commit/e8c1a5ff2346d40be5f2450044c01c845777cc02

--- absl/log/internal/check_op.h.orig	2025-08-14 19:54:55.000000000 +0000
+++ absl/log/internal/check_op.h
@@ -375,6 +375,18 @@ std::enable_if_t<std::negation_v<std::di
                  UnprintableWrapper>
 Detect(...);
 
+// Equivalent to the updated std::underlying_type from C++20, which is no
+// longer undefined behavior for non-enum types.
+template <typename T, typename EnableT = void>
+struct UnderlyingType {};
+
+template <typename T>
+struct UnderlyingType<T, std::enable_if_t<std::is_enum_v<T>>> {
+  using type = std::underlying_type_t<T>;
+};
+template <typename T>
+using UnderlyingTypeT = typename UnderlyingType<T>::type;
+
 // This overload triggers when T is a scoped enum that has not defined an output
 // stream operator (operator<<) or AbslStringify. It causes the enum value to be
 // converted to a type that can be streamed. For consistency with other enums, a
@@ -386,12 +398,12 @@ std::enable_if_t<
         std::is_enum<T>, std::negation<std::is_convertible<T, int>>,
         std::negation<is_streamable<T>>, std::negation<HasAbslStringify<T>>>,
     std::conditional_t<
-        std::is_same_v<std::underlying_type_t<T>, bool> ||
-            std::is_same_v<std::underlying_type_t<T>, char> ||
-            std::is_same_v<std::underlying_type_t<T>, signed char> ||
-            std::is_same_v<std::underlying_type_t<T>, unsigned char>,
-        std::underlying_type_t<T>,
-        std::conditional_t<std::is_signed_v<std::underlying_type_t<T>>, int64_t,
+        std::is_same_v<UnderlyingTypeT<T>, bool> ||
+            std::is_same_v<UnderlyingTypeT<T>, char> ||
+            std::is_same_v<UnderlyingTypeT<T>, signed char> ||
+            std::is_same_v<UnderlyingTypeT<T>, unsigned char>,
+        UnderlyingTypeT<T>,
+        std::conditional_t<std::is_signed_v<UnderlyingTypeT<T>>, int64_t,
                            uint64_t>>>
 Detect(...);
 }  // namespace detect_specialization

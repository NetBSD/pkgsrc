$NetBSD: patch-tests_src_unit-user__defined__input.cpp,v 1.1 2025/04/27 20:07:25 wiz Exp $

https://github.com/nlohmann/json/pull/4763

--- tests/src/unit-user_defined_input.cpp.orig	2025-04-11 08:42:28.000000000 +0000
+++ tests/src/unit-user_defined_input.cpp
@@ -60,12 +60,12 @@ TEST_CASE("Custom container member begin
     {
         const char* data;
 
-        const char* begin() const
+        const char* begin() const noexcept
         {
             return data;
         }
 
-        const char* end() const
+        const char* end() const noexcept
         {
             return data + strlen(data); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
         }

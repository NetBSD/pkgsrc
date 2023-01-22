$NetBSD: patch-lib_base_string.cpp,v 1.3 2023/01/22 17:34:20 ryoon Exp $

Fix build with Boost 1.81.0
From: https://github.com/Icinga/icinga2/commit/5bcbc96e221bb3aafc370449941bfbd70939915c

--- lib/base/string.cpp.orig	2022-06-29 17:15:18.000000000 +0000
+++ lib/base/string.cpp
@@ -128,15 +128,15 @@ String::operator const std::string&() co
 }
 
 /**
- * Conversion function to boost::string_view.
+ * Conversion function to boost::beast::string_view.
  *
  * This allows using String as the value for HTTP headers in boost::beast::http::basic_fields::set.
  *
- * @return A boost::string_view representing this string.
+ * @return A boost::beast::string_view representing this string.
  */
-String::operator boost::string_view() const
+String::operator boost::beast::string_view() const
 {
-	return boost::string_view(m_Data);
+	return boost::beast::string_view(m_Data);
 }
 
 const char *String::CStr() const

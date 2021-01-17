$NetBSD: patch-lib_base_string.cpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit eab07a7318f9e42157bc21d86585340d762759e7

--- lib/base/string.cpp.orig
+++ lib/base/string.cpp
@@ -127,6 +127,18 @@ String::operator const std::string&() const
 	return m_Data;
 }
 
+/**
+ * Conversion function to boost::string_view.
+ *
+ * This allows using String as the value for HTTP headers in boost::beast::http::basic_fields::set.
+ *
+ * @return A boost::string_view representing this string.
+ */
+String::operator boost::string_view() const
+{
+	return boost::string_view(m_Data);
+}
+
 const char *String::CStr() const
 {
 	return m_Data.c_str();

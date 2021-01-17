$NetBSD: patch-lib_base_string.hpp,v 1.2 2021/01/17 13:22:26 wiz Exp $

Support Boost 1.74 when setting HTTP headers
Upstream Issue #8185, Pull Request #8575, commit eab07a7318f9e42157bc21d86585340d762759e7

--- lib/base/string.hpp.orig
+++ lib/base/string.hpp
@@ -6,6 +6,7 @@
 #include "base/i2-base.hpp"
 #include "base/object.hpp"
 #include <boost/range/iterator.hpp>
+#include <boost/utility/string_view.hpp>
 #include <string>
 #include <iosfwd>
 
@@ -71,6 +72,7 @@ public:
 	bool operator<(const String& rhs) const;
 
 	operator const std::string&() const;
+	operator boost::string_view() const;
 
 	const char *CStr() const;
 

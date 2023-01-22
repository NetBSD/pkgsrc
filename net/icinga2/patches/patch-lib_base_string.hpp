$NetBSD: patch-lib_base_string.hpp,v 1.3 2023/01/22 17:34:20 ryoon Exp $

Fix build with Boost 1.81.0
From: https://github.com/Icinga/icinga2/commit/5bcbc96e221bb3aafc370449941bfbd70939915c

--- lib/base/string.hpp.orig	2022-06-29 17:15:18.000000000 +0000
+++ lib/base/string.hpp
@@ -5,6 +5,7 @@
 
 #include "base/i2-base.hpp"
 #include "base/object.hpp"
+#include <boost/beast/core.hpp>
 #include <boost/range/iterator.hpp>
 #include <boost/utility/string_view.hpp>
 #include <string>
@@ -72,7 +73,7 @@ public:
 	bool operator<(const String& rhs) const;
 
 	operator const std::string&() const;
-	operator boost::string_view() const;
+	operator boost::beast::string_view() const;
 
 	const char *CStr() const;
 

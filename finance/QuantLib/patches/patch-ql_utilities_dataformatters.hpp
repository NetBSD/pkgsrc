$NetBSD: patch-ql_utilities_dataformatters.hpp,v 1.1 2020/04/17 00:19:09 joerg Exp $

--- ql/utilities/dataformatters.hpp.orig	2020-04-16 17:50:51.479075151 +0000
+++ ql/utilities/dataformatters.hpp
@@ -25,6 +25,7 @@
 #define quantlib_data_formatters_hpp
 
 #include <ql/utilities/null.hpp>
+#include <ostream>
 #include <iosfwd>
 
 namespace QuantLib {

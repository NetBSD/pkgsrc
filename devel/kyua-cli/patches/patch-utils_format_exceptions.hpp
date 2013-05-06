$NetBSD: patch-utils_format_exceptions.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/format/exceptions.hpp.orig	2013-05-06 08:27:56.000000000 +0000
+++ utils/format/exceptions.hpp
@@ -33,6 +33,7 @@
 #define UTILS_FORMAT_EXCEPTIONS_HPP
 
 #include <stdexcept>
+#include <string>
 
 namespace utils {
 namespace format {

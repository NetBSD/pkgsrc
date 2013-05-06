$NetBSD: patch-utils_cmdline_exceptions.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/cmdline/exceptions.hpp.orig	2013-05-06 08:24:33.000000000 +0000
+++ utils/cmdline/exceptions.hpp
@@ -33,6 +33,7 @@
 #define UTILS_CMDLINE_EXCEPTIONS_HPP
 
 #include <stdexcept>
+#include <string>
 
 namespace utils {
 namespace cmdline {

$NetBSD: patch-utils_fs_exceptions.hpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/fs/exceptions.hpp.orig	2013-05-06 08:21:46.000000000 +0000
+++ utils/fs/exceptions.hpp
@@ -33,6 +33,7 @@
 #define UTILS_FS_EXCEPTIONS_HPP
 
 #include <stdexcept>
+#include <string>
 
 namespace utils {
 namespace fs {

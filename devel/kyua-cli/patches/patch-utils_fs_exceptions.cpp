$NetBSD: patch-utils_fs_exceptions.cpp,v 1.1 2013/05/06 14:46:58 joerg Exp $

--- utils/fs/exceptions.cpp.orig	2013-05-06 08:21:29.000000000 +0000
+++ utils/fs/exceptions.cpp
@@ -29,6 +29,7 @@
 #include "utils/fs/exceptions.hpp"
 
 #include <cstring>
+#include <string>
 
 #include "utils/format/macros.hpp"
 

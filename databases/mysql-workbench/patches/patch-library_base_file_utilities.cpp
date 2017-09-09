$NetBSD: patch-library_base_file_utilities.cpp,v 1.4 2017/09/09 15:23:30 dholland Exp $

Use standard headers.

--- library/base/file_utilities.cpp.orig	2011-03-17 12:48:44.000000000 +0000
+++ library/base/file_utilities.cpp
@@ -29,7 +29,9 @@
 #else
 #include <errno.h>
 #include <fcntl.h>
+#include <sys/types.h>
 #include <sys/file.h>
+#include <sys/stat.h>
 #endif
 
 namespace base {

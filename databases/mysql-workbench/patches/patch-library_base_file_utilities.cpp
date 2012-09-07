$NetBSD: patch-library_base_file_utilities.cpp,v 1.2 2012/09/07 19:16:20 adam Exp $

--- library/base/file_utilities.cpp.orig	2012-08-09 20:56:59.000000000 +0000
+++ library/base/file_utilities.cpp
@@ -32,6 +32,9 @@
 #include <fcntl.h>
 #include <sys/file.h>
 #endif
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 
 namespace base {
   

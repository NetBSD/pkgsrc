$NetBSD: patch-router_src_harness_src_stdx_io_file_handle.cc,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

Support for NetBSD - reuses F_GETPATH code originally for macOS. Also
use correct constant for the fcntl() code - PATH_MAX, not MAXPATHLEN

--- router/src/harness/src/stdx/io/file_handle.cc.orig	2021-03-22 08:44:50.000000000 +0000
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -47,8 +47,6 @@
 #include <sys/user.h>
 
 #include <vector>
-#elif defined(__APPLE__)
-#include <sys/param.h>  // MAXPATHLEN
 #endif
 
 #include "mysql/harness/stdx/expected.h"
@@ -233,9 +230,9 @@ file_handle::current_path() const noexce
   }
 
   return {std::string{path.data(), std::next(path.data(), sz)}};
-#elif defined(__APPLE__)
+#elif defined(F_GETPATH) // __APPLE__, __NetBSD__
   std::string path_name;
-  path_name.resize(MAXPATHLEN + 1);
+  path_name.resize(PATH_MAX + 1);
 
   if (-1 == fcntl(handle_, F_GETPATH, &path_name.front())) {
     return stdx::make_unexpected(last_error_code());

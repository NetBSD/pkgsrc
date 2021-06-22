$NetBSD: patch-router_src_harness_src_stdx_io_file_handle.cc,v 1.2 2021/06/22 10:12:37 nia Exp $

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
@@ -169,14 +167,15 @@ file_handle::current_path() const noexce
         make_error_code(std::errc::bad_file_descriptor));
   }
 
-#if defined(__linux__) || defined(__sun)
+#if defined(__linux__) || defined(__sun) || \
+   (defined(__NetBSD__) && !defined(F_GETPATH))
   const std::string in =
-#if defined(__linux__)
-      // /proc/self/fd/<id> is a symlink to the actual file
-      "/proc/self/fd/"s
-#else
+#if defined(__sun)
       // /proc/<pid>/path/<id> is a symlink to the actual file
       "/proc/"s + std::to_string(getpid()) + "/path/"s
+#else
+      // /proc/self/fd/<id> is a symlink to the actual file
+      "/proc/self/fd/"s
 #endif
       + std::to_string(handle_);
 
@@ -233,9 +232,9 @@ file_handle::current_path() const noexce
   }
 
   return {std::string{path.data(), std::next(path.data(), sz)}};
-#elif defined(__APPLE__)
+#elif defined(F_GETPATH) // __APPLE__, __NetBSD__
   std::string path_name;
-  path_name.resize(MAXPATHLEN + 1);
+  path_name.resize(PATH_MAX + 1);
 
   if (-1 == fcntl(handle_, F_GETPATH, &path_name.front())) {
     return stdx::make_unexpected(last_error_code());

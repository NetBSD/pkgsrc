$NetBSD: patch-libs_process_src_posix_close__handles.cpp,v 1.2 2024/12/29 14:53:14 adam Exp $

* dirfd is a macro for NetBSD.

--- libs/process/src/posix/close_handles.cpp.orig	2024-12-26 18:22:58.367981291 +0000
+++ libs/process/src/posix/close_handles.cpp
@@ -185,7 +185,7 @@ void close_all(const std::vector<int> & 
         return ;
     }
 
-    auto dir_fd = ::dirfd(dir.get());
+    auto dir_fd = dirfd(dir.get());
     if (dir_fd == -1)
     {
         ec = BOOST_PROCESS_V2_NAMESPACE::detail::get_last_error();

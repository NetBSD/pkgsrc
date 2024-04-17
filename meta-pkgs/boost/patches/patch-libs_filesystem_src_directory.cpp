$NetBSD: patch-libs_filesystem_src_directory.cpp,v 1.1 2024/04/17 16:14:02 adam Exp $

Fix "error: expected id-expression before '(' token" (dirfd() is defined as a macro on NetBSD).

--- libs/filesystem/src/directory.cpp.orig	2024-04-17 15:57:53.477376790 +0000
+++ libs/filesystem/src/directory.cpp
@@ -279,7 +279,7 @@ inline system::error_code dir_itr_close(
 // Obtains a file descriptor from the directory iterator
 inline int dir_itr_fd(dir_itr_imp const& imp, system::error_code& ec)
 {
-    int fd = ::dirfd(static_cast< DIR* >(imp.handle));
+    int fd = dirfd(static_cast< DIR* >(imp.handle));
     if (BOOST_UNLIKELY(fd < 0))
     {
         int err = errno;

$NetBSD: patch-lib_Support_Unix_Path.inc,v 1.1 2017/05/05 18:12:24 joerg Exp $

SVN r302263

--- lib/Support/Unix/Path.inc.orig	2017-05-04 16:08:02.765430627 +0000
+++ lib/Support/Unix/Path.inc
@@ -342,14 +342,15 @@ std::error_code resize_file(int FD, uint
 #if defined(HAVE_POSIX_FALLOCATE)
   // If we have posix_fallocate use it. Unlike ftruncate it always allocates
   // space, so we get an error if the disk is full.
-  if (int Err = ::posix_fallocate(FD, 0, Size))
-    return std::error_code(Err, std::generic_category());
-#else
+  if (int Err = ::posix_fallocate(FD, 0, Size)) {
+    if (Err != EOPNOTSUPP)
+      return std::error_code(Err, std::generic_category());
+  }
+#endif
   // Use ftruncate as a fallback. It may or may not allocate space. At least on
   // OS X with HFS+ it does.
   if (::ftruncate(FD, Size) == -1)
     return std::error_code(errno, std::generic_category());
-#endif
 
   return std::error_code();
 }

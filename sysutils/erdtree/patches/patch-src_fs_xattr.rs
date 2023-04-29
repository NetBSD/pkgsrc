$NetBSD: patch-src_fs_xattr.rs,v 1.1 2023/04/29 15:59:58 pin Exp $

Fix build on non-linux systems.
https://github.com/solidiquis/erdtree/pull/160

--- src/fs/xattr.rs.orig	2023-04-26 05:18:54.000000000 +0000
+++ src/fs/xattr.rs
@@ -30,7 +30,7 @@ unsafe fn has_xattrs(path: &Path) -> boo
         slice_ptr.cast::<c_char>()
     };
 
-    #[cfg(target_os = "linux")]
+    #[cfg(not(target_os = "macos"))]
     return 0 < listxattr(path_ptr, ptr::null_mut::<c_char>(), 0);
 
     #[cfg(target_os = "macos")]

$NetBSD: patch-vendor_fs__at-0.1.4_src_unix.rs,v 1.1 2023/04/11 08:42:00 pin Exp $

NetBSD doesn't define O_PATH,
https://github.com/rbtcollins/fs_at/pull/74

--- ../vendor/fs_at-0.1.4/src/unix.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/fs_at-0.1.4/src/unix.rs
@@ -124,7 +124,7 @@ impl OpenOptionsImpl {
         self._open_at(d, path, flags)
     }
 
-    #[cfg(not(target_os = "macos"))]
+    #[cfg(all(not(target_os = "macos"), not(target_os = "netbsd")))]
     pub fn open_path_at(&self, d: &File, path: &Path) -> Result<File> {
         let flags =
             libc::O_RDONLY | libc::O_NOFOLLOW | libc::O_PATH | libc::O_CLOEXEC | libc::O_NOCTTY;

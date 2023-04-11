$NetBSD: patch-vendor_fs__at-0.1.4_src_lib.rs,v 1.1 2023/04/11 08:42:00 pin Exp $

NetBSD doesn't define O_PATH,
https://github.com/rbtcollins/fs_at/pull/74

--- ../vendor/fs_at-0.1.4/src/lib.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/fs_at-0.1.4/src/lib.rs
@@ -323,7 +323,7 @@ impl OpenOptions {
     /// restricted.
     ///
     /// MacOSX: Not implemented as O_PATH is not defined.
-    #[cfg(not(target_os = "macos"))]
+    #[cfg(all(not(target_os = "macos"), not(target_os = "netbsd")))]
     pub fn open_path_at<P: AsRef<Path>>(&self, d: &File, p: P) -> Result<File> {
         self._impl
             .open_path_at(d, OpenOptions::ensure_rootless(p.as_ref())?)
@@ -519,7 +519,7 @@ pub mod testsupport;
 
 #[cfg(test)]
 mod tests {
-    #[cfg(not(target_os = "macos"))]
+    #[cfg(all(not(target_os = "macos"), not(target_os = "netbsd")))]
     use std::path::Path;
     use std::{
         ffi::OsStr,
@@ -1191,7 +1191,7 @@ mod tests {
         Ok(())
     }
 
-    #[cfg(not(target_os = "macos"))]
+    #[cfg(all(not(target_os = "macos"), not(target_os = "netbsd")))]
     #[test]
     fn open_path_at() -> Result<()> {
         let (_tmp, parent_dir, _pathname) = setup()?;

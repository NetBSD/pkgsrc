$NetBSD: patch-library_std_src_os_linux_fs.rs,v 1.1 2021/01/01 20:44:48 he Exp $

Disambiguate reference; on some targets we get a warning turned into
error that this is both a function and a struct.

--- library/std/src/os/linux/fs.rs.orig	2020-11-16 14:01:53.000000000 +0000
+++ library/std/src/os/linux/fs.rs
@@ -20,7 +20,7 @@ pub trait MetadataExt {
     /// Unix platforms. The `os::unix::fs::MetadataExt` trait contains the
     /// cross-Unix abstractions contained within the raw stat.
     ///
-    /// [`stat`]: crate::os::linux::raw::stat
+    /// [`stat`]: struct@crate::os::linux::raw::stat
     ///
     /// # Examples
     ///

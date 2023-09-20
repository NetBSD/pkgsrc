$NetBSD: patch-.._vendor_uucore-0.0.21_src_lib_features_fs.rs,v 1.1 2023/09/20 08:54:24 pin Exp $

Add support for NetBSD.
https://github.com/uutils/coreutils/pull/5289

--- ../vendor/uucore-0.0.21/src/lib/features/fs.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/uucore-0.0.21/src/lib/features/fs.rs
@@ -114,6 +114,7 @@ impl FileInformation {
             not(target_vendor = "apple"),
             not(target_os = "android"),
             not(target_os = "freebsd"),
+            not(target_os = "netbsd"),
             not(target_arch = "aarch64"),
             not(target_arch = "riscv64"),
             target_pointer_width = "64"
@@ -125,6 +126,7 @@ impl FileInformation {
                 target_vendor = "apple",
                 target_os = "android",
                 target_os = "freebsd",
+                target_os = "netbsd",
                 target_arch = "aarch64",
                 target_arch = "riscv64",
                 not(target_pointer_width = "64")
@@ -137,9 +139,16 @@ impl FileInformation {
 
     #[cfg(unix)]
     pub fn inode(&self) -> u64 {
-        #[cfg(all(not(target_os = "freebsd"), target_pointer_width = "64"))]
+        #[cfg(all(
+            not(any(target_os = "freebsd", target_os = "netbsd")),
+            target_pointer_width = "64"
+        ))]
         return self.0.st_ino;
-        #[cfg(any(target_os = "freebsd", not(target_pointer_width = "64")))]
+        #[cfg(any(
+            target_os = "freebsd",
+            target_os = "netbsd",
+            not(target_pointer_width = "64")
+        ))]
         return self.0.st_ino.into();
     }
 }

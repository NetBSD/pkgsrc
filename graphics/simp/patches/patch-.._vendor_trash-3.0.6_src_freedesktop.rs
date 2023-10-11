$NetBSD: patch-.._vendor_trash-3.0.6_src_freedesktop.rs,v 1.1 2023/10/11 11:39:56 pin Exp $

https://github.com/Byron/trash-rs/pull/84

--- ../vendor/trash-3.0.6/src/freedesktop.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/trash-3.0.6/src/freedesktop.rs
@@ -700,12 +700,12 @@ fn get_mount_points() -> Result<Vec<Moun
             std::str::from_utf8(buf).ok()
         }
     }
-    let mut fs_infos: *mut libc::statfs = std::ptr::null_mut();
+    let mut fs_infos: *mut libc::statvfs = std::ptr::null_mut();
     let count = unsafe { libc::getmntinfo(&mut fs_infos, libc::MNT_WAIT) };
     if count < 1 {
         return Ok(Vec::new());
     }
-    let fs_infos: &[libc::statfs] = unsafe { std::slice::from_raw_parts(fs_infos as _, count as _) };
+    let fs_infos: &[libc::statvfs] = unsafe { std::slice::from_raw_parts(fs_infos as _, count as _) };
 
     let mut result = Vec::new();
     for fs_info in fs_infos {

$NetBSD: patch-src_path.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Use statvfs() on illumos.

--- src/path.rs.orig	2025-11-24 15:30:10.536505320 +0000
+++ src/path.rs
@@ -694,7 +694,7 @@ pub fn path_remoteness(path: &wstr) -> D
     }
 
     // NetBSD doesn't have statfs, but MNT_LOCAL works for statvfs.
-    #[cfg(target_os = "netbsd")]
+    #[cfg(any(target_os = "netbsd", target_os = "illumos"))]
     {
         let mut buf = MaybeUninit::uninit();
         if unsafe { libc::statvfs(narrow.as_ptr(), buf.as_mut_ptr()) } < 0 {
@@ -711,7 +711,7 @@ pub fn path_remoteness(path: &wstr) -> D
         }
     }
 
-    #[cfg(not(any(target_os = "linux", target_os = "netbsd", cygwin)))]
+    #[cfg(not(any(target_os = "linux", target_os = "netbsd", target_os = "illumos", cygwin)))]
     {
         let mut buf = MaybeUninit::uninit();
         if unsafe { libc::statfs(narrow.as_ptr(), buf.as_mut_ptr()) } < 0 {

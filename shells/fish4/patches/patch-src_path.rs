$NetBSD: patch-src_path.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Use statvfs() on illumos.

--- src/path.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/path.rs
@@ -722,14 +722,14 @@ pub fn path_remoteness(path: &wstr) -> D
         }
         // ST_LOCAL is a flag to statvfs, which is itself standardized.
         // In practice the only system to define it is NetBSD.
-        #[cfg(target_os = "netbsd")]
+        #[cfg(any(target_os = "netbsd", target_os = "illumos"))]
         let remoteness = remoteness_via_statfs(
             libc::statvfs,
             |stat: &libc::statvfs| stat.f_flag,
             crate::libc::ST_LOCAL(),
             &narrow,
         );
-        #[cfg(not(target_os = "netbsd"))]
+        #[cfg(not(any(target_os = "netbsd", target_os = "illumos")))]
         let remoteness = remoteness_via_statfs(
             libc::statfs,
             |stat: &libc::statfs| stat.f_flags,

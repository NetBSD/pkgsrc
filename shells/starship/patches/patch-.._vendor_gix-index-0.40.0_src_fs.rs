$NetBSD: patch-.._vendor_gix-index-0.40.0_src_fs.rs,v 1.1 2025/05/10 11:01:18 pin Exp $

Fix build with new rustix
https://github.com/GitoxideLabs/gitoxide/pull/2005/

--- ../vendor/gix-index-0.40.0/src/fs.rs.orig	2025-05-10 10:29:01.812866975 +0000
+++ ../vendor/gix-index-0.40.0/src/fs.rs
@@ -59,10 +59,8 @@ impl Metadata {
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let seconds = self.0.st_mtim.tv_sec;
 
-            #[cfg(not(any(target_os = "netbsd", target_os = "aix", target_os = "hurd")))]
+            #[cfg(not(any(target_os = "aix", target_os = "hurd")))]
             let nanoseconds = self.0.st_mtime_nsec;
-            #[cfg(target_os = "netbsd")]
-            let nanoseconds = self.0.st_mtimensec;
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let nanoseconds = self.0.st_mtim.tv_nsec;
 
@@ -88,10 +86,8 @@ impl Metadata {
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let seconds = self.0.st_ctim.tv_sec;
 
-            #[cfg(not(any(target_os = "netbsd", target_os = "aix", target_os = "hurd")))]
+            #[cfg(not(any(target_os = "aix", target_os = "hurd")))]
             let nanoseconds = self.0.st_ctime_nsec;
-            #[cfg(target_os = "netbsd")]
-            let nanoseconds = self.0.st_ctimensec;
             #[cfg(any(target_os = "aix", target_os = "hurd"))]
             let nanoseconds = self.0.st_ctim.tv_nsec;
 

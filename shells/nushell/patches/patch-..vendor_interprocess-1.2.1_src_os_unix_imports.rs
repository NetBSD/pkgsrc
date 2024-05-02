$NetBSD: patch-..vendor_interprocess-1.2.1_src_os_unix_imports.rs,v 1.1 2024/05/02 08:08:51 pin Exp $

NetBSD has uucred and not xucred.

--- ../vendor/interprocess-1.2.1/src/os/unix/imports.rs.orig	2024-05-02 07:34:36.709869722 +0000
+++ ../vendor/interprocess-1.2.1/src/os/unix/imports.rs
@@ -39,11 +39,14 @@ pub(super) use libc::{
 };
 
 cfg_if! {
-    if #[cfg(uds_ucred)] {
+        if #[cfg(uds_ucred)] {
         pub(super) use libc::ucred;
-    } else if #[cfg(uds_xucred)] {
+    } else if #[cfg(all(uds_xucred, not(target_os = "netbsd")))] {
         pub(super) use libc::xucred;
         pub struct ucred {}
+    } else if #[cfg(all(uds_uucred, target_os = "netbsd"))] {
+        pub(super) use libc::uucred;
+        pub struct ucred {}
     } else {
         pub struct ucred {}
     }

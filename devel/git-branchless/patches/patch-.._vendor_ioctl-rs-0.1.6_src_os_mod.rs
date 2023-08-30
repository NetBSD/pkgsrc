$NetBSD: patch-.._vendor_ioctl-rs-0.1.6_src_os_mod.rs,v 1.1 2023/08/30 08:30:17 pin Exp $

Add bsiegert@ unmerged pull request
https://github.com/dcuddeback/ioctl-rs/pull/5

--- ../vendor/ioctl-rs-0.1.6/src/os/mod.rs.orig	2017-11-20 03:11:32.000000000 +0000
+++ ../vendor/ioctl-rs-0.1.6/src/os/mod.rs
@@ -12,3 +12,6 @@ pub mod dragonfly;
 
 #[cfg(target_os = "openbsd")]
 pub mod openbsd;
+
+#[cfg(target_os = "netbsd")]
+pub mod netbsd;

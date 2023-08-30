$NetBSD: patch-.._vendor_ioctl-rs-0.1.6_src_lib.rs,v 1.1 2023/08/30 08:30:17 pin Exp $

Add bsiegert@ unmerged pull request
https://github.com/dcuddeback/ioctl-rs/pull/5

--- ../vendor/ioctl-rs-0.1.6/src/lib.rs.orig	2017-11-20 03:11:32.000000000 +0000
+++ ../vendor/ioctl-rs-0.1.6/src/lib.rs
@@ -21,6 +21,9 @@ pub use os::dragonfly::*;
 #[cfg(target_os = "openbsd")]
 pub use os::openbsd::*;
 
+#[cfg(target_os = "netbsd")]
+pub use os::netbsd::*;
+
 mod os;
 
 

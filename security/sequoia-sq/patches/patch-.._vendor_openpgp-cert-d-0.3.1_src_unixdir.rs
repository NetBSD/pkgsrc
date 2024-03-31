$NetBSD: patch-.._vendor_openpgp-cert-d-0.3.1_src_unixdir.rs,v 1.3 2024/03/31 22:37:55 wiz Exp $

Fix build on NetBSD.
https://gitlab.com/sequoia-pgp/pgp-cert-d/-/merge_requests/99/diffs

--- ../vendor/openpgp-cert-d-0.3.1/src/unixdir.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/openpgp-cert-d-0.3.1/src/unixdir.rs
@@ -67,9 +67,17 @@ impl Metadata {
 
     /// The modification time as the time since the Unix epoch.
     pub fn modified(&self) -> std::time::Duration {
-        std::time::Duration::new(
+        // Netbsd-like systems.  See:
+        // https://github.com/rust-lang/libc/blob/a0f5b4b21391252fe38b2df9310dc65e37b07d9f/src/unix/bsd/mod.rs#L931
+        #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
+        return std::time::Duration::new(
             self.0.st_mtime as u64,
-            self.0.st_mtime_nsec as u32)
+            self.0.st_mtimensec as u32);
+
+        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd")))]
+        return std::time::Duration::new(
+            self.0.st_mtime as u64,
+            self.0.st_mtime_nsec as u32);
     }
 
     /// Whether a file is a directory.

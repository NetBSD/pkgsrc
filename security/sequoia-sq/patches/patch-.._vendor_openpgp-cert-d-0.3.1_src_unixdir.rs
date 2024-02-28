$NetBSD: patch-.._vendor_openpgp-cert-d-0.3.1_src_unixdir.rs,v 1.1 2024/02/28 16:33:38 wiz Exp $

NetBSD has st_mtimensec

--- ../vendor/openpgp-cert-d-0.3.1/src/unixdir.rs.orig	2024-02-28 14:58:05.502259036 +0000
+++ ../vendor/openpgp-cert-d-0.3.1/src/unixdir.rs
@@ -69,7 +69,7 @@ impl Metadata {
     pub fn modified(&self) -> std::time::Duration {
         std::time::Duration::new(
             self.0.st_mtime as u64,
-            self.0.st_mtime_nsec as u32)
+            self.0.st_mtimensec as u32)
     }
 
     /// Whether a file is a directory.

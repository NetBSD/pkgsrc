$NetBSD: patch-.._vendor_pam-sys-1.0.0-alpha5_build.rs,v 1.1 2026/11/02 16:03:40 pin Exp $

Emit OpenPAM's named enums as plain constants.

--- ../vendor/pam-sys-1.0.0-alpha5/build.rs.orig	2026-11-02 14:25:19.617967091 +0000
+++ ../vendor/pam-sys-1.0.0-alpha5/build.rs
@@ -58,6 +58,9 @@ fn main() {
     } else if cfg!(target_os = "freebsd") || cfg!(target_os = "netbsd") {
         // XXX: this should include all OS that use openPAM
         builder = builder
+            // OpenPAM declares item types and message styles in named enums
+            .allowlist_type("openpam_.*")
+            .prepend_enum_name(false)
             // Use libc types so our signatures are slightly nicer
             .raw_line("use libc::passwd;")
             .blocklist_type("passwd");

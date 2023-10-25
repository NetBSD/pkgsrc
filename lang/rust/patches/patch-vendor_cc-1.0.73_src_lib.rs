$NetBSD: patch-vendor_cc-1.0.73_src_lib.rs,v 1.3 2023/10/25 05:50:43 pin Exp $

Use correct ABI on NetBSD/riscv64.

--- vendor/cc-1.0.73/src/lib.rs.orig	2023-05-31 21:44:47.000000000 +0000
+++ vendor/cc-1.0.73/src/lib.rs
@@ -1830,6 +1830,9 @@ impl Build {
                         } else if target.contains("freebsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());
+                        } else if target.contains("netbsd") && arch.starts_with("64") {
+                            cmd.args.push(("-march=rv64gc").into());
+                            cmd.args.push("-mabi=lp64d".into());
                         } else if target.contains("openbsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());

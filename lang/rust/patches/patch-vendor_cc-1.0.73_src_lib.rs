$NetBSD: patch-vendor_cc-1.0.73_src_lib.rs,v 1.5 2024/10/13 19:04:39 he Exp $

Use correct ABI on NetBSD/riscv64.

--- vendor/cc-1.0.79/src/lib.rs.orig	2024-08-29 17:57:16.678636324 +0000
+++ vendor/cc-1.0.79/src/lib.rs
@@ -1946,6 +1946,9 @@ impl Build {
                         } else if target.contains("freebsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());
+                        } else if target.contains("netbsd") && arch.starts_with("64") {
+                            cmd.args.push(("-march=rv64gc").into());
+                            cmd.args.push("-mabi=lp64d".into());
                         } else if target.contains("openbsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());

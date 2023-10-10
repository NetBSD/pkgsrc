$NetBSD: patch-library_core_src_ffi_mod.rs,v 1.2 2023/10/10 13:12:33 pin Exp $

NetBSD/riscv64 also has unsigned chars.

--- library/core/src/ffi/mod.rs.orig	2023-05-31 19:28:10.000000000 +0000
+++ library/core/src/ffi/mod.rs
@@ -132,7 +132,12 @@ mod c_char_definition {
             ),
             all(
                 target_os = "netbsd",
-                any(target_arch = "aarch64", target_arch = "arm", target_arch = "powerpc")
+                any(
+		    target_arch = "aarch64",
+                    target_arch = "arm",
+                    target_arch = "powerpc",
+                    target_arch = "riscv64"
+                )
             ),
             all(
                 target_os = "vxworks",

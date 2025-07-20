$NetBSD: patch-.._vendor_lexical-parse-float-1.0.5_src_number.rs,v 1.1 2025/07/20 12:17:05 he Exp $

Tolerate the i586 definition of set_precision().
Ref. https://github.com/Alexhuszagh/rust-lexical/pull/219

--- ../vendor/lexical-parse-float-1.0.5/src/number.rs.orig	2025-07-20 11:52:04.990329389 +0000
+++ ../vendor/lexical-parse-float-1.0.5/src/number.rs
@@ -74,7 +74,7 @@ impl Number<'_> {
         // function takes care of setting the precision on architectures which
         // require setting it by changing the global state (like the control word of the
         // x87 FPU).
-        let _cw: () = set_precision::<F>();
+        let _cw = set_precision::<F>();
 
         if self.is_fast_path::<F, FORMAT>() {
             let radix = format.radix();

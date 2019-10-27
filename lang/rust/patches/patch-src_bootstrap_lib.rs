$NetBSD: patch-src_bootstrap_lib.rs,v 1.5 2019/10/27 18:34:27 he Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name
Also, don't make warnings fatal -- 1.38.0 warns about a construct
when building 1.38.0, ref.
  https://github.com/rust-lang/rust/issues/65722

--- src/bootstrap/lib.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -104,7 +104,7 @@
 //! also check out the `src/bootstrap/README.md` file for more information.
 
 // NO-RUSTC-WRAPPER
-#![deny(warnings, rust_2018_idioms, unused_lifetimes)]
+#![deny(rust_2018_idioms, unused_lifetimes)]
 
 #![feature(core_intrinsics)]
 #![feature(drain_filter)]
@@ -768,7 +768,6 @@ impl Build {
         // cc-rs because the build scripts will determine that for themselves.
         let mut base = self.cc[&target].args().iter()
                            .map(|s| s.to_string_lossy().into_owned())
-                           .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
                            .collect::<Vec<String>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
@@ -779,6 +778,11 @@ impl Build {
             base.push("-stdlib=libc++".into());
         }
 
+        // FreeBSD (from 10.2) also uses libc++.
+        if target.contains("freebsd") {
+            base.push("-stdlib=libc++".into());
+        }
+
         // Work around an apparently bad MinGW / GCC optimization,
         // See: http://lists.llvm.org/pipermail/cfe-dev/2016-December/051980.html
         // See: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=78936

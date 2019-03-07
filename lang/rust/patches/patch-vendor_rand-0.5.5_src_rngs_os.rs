$NetBSD: patch-vendor_rand-0.5.5_src_rngs_os.rs,v 1.1 2019/03/07 20:19:11 jperkin Exp $

Explicitly disable getrandom support on SunOS, the test fails.
https://github.com/rust-random/rand/issues/637

--- vendor/rand-0.5.5/src/rngs/os.rs.orig	2019-02-28 10:22:24.000000000 +0000
+++ vendor/rand-0.5.5/src/rngs/os.rs
@@ -675,6 +675,7 @@ mod imp {
     }
 
     fn getrandom(buf: &mut [u8], blocking: bool) -> libc::c_long {
+        return -1;
         extern "C" {
             fn syscall(number: libc::c_long, ...) -> libc::c_long;
         }

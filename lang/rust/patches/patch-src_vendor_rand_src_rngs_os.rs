$NetBSD: patch-src_vendor_rand_src_rngs_os.rs,v 1.1 2018/10/31 15:53:18 jperkin Exp $

Explicitly disable getrandom support on SunOS, the test fails.
https://github.com/rust-random/rand/issues/637

--- src/vendor/rand/src/rngs/os.rs.orig	2018-10-24 21:38:28.000000000 +0000
+++ src/vendor/rand/src/rngs/os.rs
@@ -675,6 +675,7 @@ mod imp {
     }
 
     fn getrandom(buf: &mut [u8], blocking: bool) -> libc::c_long {
+        return -1;
         extern "C" {
             fn syscall(number: libc::c_long, ...) -> libc::c_long;
         }

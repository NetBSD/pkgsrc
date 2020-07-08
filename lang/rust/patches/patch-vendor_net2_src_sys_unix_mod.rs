$NetBSD: patch-vendor_net2_src_sys_unix_mod.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/net2/src/sys/unix/mod.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/net2/src/sys/unix/mod.rs
@@ -14,7 +14,7 @@ use std::mem;
 use std::net::{TcpListener, TcpStream, UdpSocket};
 use std::os::unix::io::FromRawFd;
 use libc::{self, c_int};
-#[cfg(not(any(target_os = "solaris", target_os = "emscripten")))]
+#[cfg(not(any(target_os = "solaris", target_os = "emscripten", target_os = "illumos")))]
 use libc::{ioctl, FIOCLEX};
 
 mod impls;
@@ -36,7 +36,7 @@ pub struct Socket {
 }
 
 impl Socket {
-    #[cfg(not(any(target_os = "solaris", target_os = "emscripten")))]
+    #[cfg(not(any(target_os = "solaris", target_os = "emscripten", target_os = "illumos")))]
     pub fn new(family: c_int, ty: c_int) -> io::Result<Socket> {
         unsafe {
             // Linux >2.6.26 overloads the type argument to accept SOCK_CLOEXEC,
@@ -58,7 +58,7 @@ impl Socket {
 
     // ioctl(FIOCLEX) is not supported by Solaris/Illumos or emscripten,
     // use fcntl(FD_CLOEXEC) instead
-    #[cfg(any(target_os = "solaris", target_os = "emscripten"))]
+    #[cfg(any(target_os = "solaris", target_os = "emscripten", target_os = "illumos"))]
     pub fn new(family: c_int, ty: c_int) -> io::Result<Socket> {
         unsafe {
             let fd = try!(::cvt(libc::socket(family, ty, 0)));

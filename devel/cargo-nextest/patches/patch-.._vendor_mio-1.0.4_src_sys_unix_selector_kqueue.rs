$NetBSD: patch-.._vendor_mio-1.0.4_src_sys_unix_selector_kqueue.rs,v 1.1 2025/12/19 13:17:10 pin Exp $

Fix build using upstream later released commit

--- ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs.orig	2025-12-04 08:47:31.211497049 +0000
+++ ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs
@@ -50,10 +50,7 @@ type Flags = u16;
 type Flags = u32;
 
 // Type of the `udata` field in the `kevent` structure.
-#[cfg(not(target_os = "netbsd"))]
 type UData = *mut libc::c_void;
-#[cfg(target_os = "netbsd")]
-type UData = libc::intptr_t;
 
 macro_rules! kevent {
     ($id: expr, $filter: expr, $flags: expr, $data: expr) => {

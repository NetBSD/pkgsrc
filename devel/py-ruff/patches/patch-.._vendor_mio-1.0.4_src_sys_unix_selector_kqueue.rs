$NetBSD: patch-.._vendor_mio-1.0.4_src_sys_unix_selector_kqueue.rs,v 1.1 2026/01/12 10:34:16 wiz Exp $

https://github.com/tokio-rs/mio/commit/625655db8e66beab8da7a6b1810bb02c045dd5cc

--- ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs.orig	2026-01-09 07:58:13.021012278 +0000
+++ ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs
@@ -46,10 +46,7 @@ type Flags = u32;
 type Flags = u32;
 
 // Type of the `udata` field in the `kevent` structure.
-#[cfg(not(target_os = "netbsd"))]
 type UData = *mut libc::c_void;
-#[cfg(target_os = "netbsd")]
-type UData = libc::intptr_t;
 
 macro_rules! kevent {
     ($id: expr, $filter: expr, $flags: expr, $data: expr) => {

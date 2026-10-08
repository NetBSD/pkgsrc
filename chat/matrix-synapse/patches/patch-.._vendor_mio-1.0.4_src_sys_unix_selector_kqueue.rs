$NetBSD: patch-.._vendor_mio-1.0.4_src_sys_unix_selector_kqueue.rs,v 1.1 2026/10/08 13:56:13 gdt Exp $

mio expects NetBSD kevent.udata to be intptr_t, but NetBSD changed it
in 2019 to void*.

mio has already fixed this in
625655db8e66beab8da7a6b1810bb02c045dd5cc.  synapse is using an old
mio.   Reported to synapse 20261008.

--- ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs.orig	2026-10-08 13:04:06.176850020 +0000
+++ ../vendor/mio-1.0.4/src/sys/unix/selector/kqueue.rs
@@ -46,10 +46,7 @@ type Flags = u16;
 type Flags = u32;
 
 // Type of the `udata` field in the `kevent` structure.
-#[cfg(not(target_os = "netbsd"))]
 type UData = *mut libc::c_void;
-#[cfg(target_os = "netbsd")]
-type UData = libc::intptr_t;
 
 macro_rules! kevent {
     ($id: expr, $filter: expr, $flags: expr, $data: expr) => {

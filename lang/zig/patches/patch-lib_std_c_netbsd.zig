$NetBSD: patch-lib_std_c_netbsd.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- lib/std/c/netbsd.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/c/netbsd.zig
@@ -1,8 +1,17 @@
 const std = @import("../std.zig");
+const builtin = std.builtin;
+
 usingnamespace std.c;
 
 extern "c" fn __errno() *c_int;
 pub const _errno = __errno;
 
-pub extern "c" fn getdents(fd: c_int, buf_ptr: [*]u8, nbytes: usize) usize;
-pub extern "c" fn sigaltstack(ss: ?*stack_t, old_ss: ?*stack_t) c_int;
+pub const dl_iterate_phdr_callback = extern fn (info: *dl_phdr_info, 
+size: usize, data: ?*c_void) c_int;
+pub extern "c" fn dl_iterate_phdr(callback: dl_iterate_phdr_callback, data: ?*c_void) c_int;
+
+pub extern "c" fn __fstat50(fd: fd_t, buf: *Stat) c_int;
+pub extern "c" fn __clock_gettime50(clk_id: c_int, tp: *timespec) c_int;
+pub extern "c" fn __clock_getres50(clk_id: c_int, tp: *timespec) c_int;
+pub extern "c" fn __getdents30(fd: c_int, buf_ptr: [*]u8, nbytes: usize) c_int;
+pub extern "c" fn __sigaltstack14(ss: ?*stack_t, old_ss: ?*stack_t) c_int;

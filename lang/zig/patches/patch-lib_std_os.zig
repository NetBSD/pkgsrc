$NetBSD: patch-lib_std_os.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- lib/std/os.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/os.zig
@@ -1841,6 +1841,16 @@ pub fn fstat(fd: fd_t) FStatError!Stat {
         }
     }
 
+    if (netbsd.is_the_target) {
+        switch (errno(system.__fstat50(fd, &stat))) {
+            0 => return stat,
+            EINVAL => unreachable,
+            EBADF => unreachable, // Always a race condition.
+            ENOMEM => return error.SystemResources,
+            else => |err| return unexpectedErrno(err),
+        }
+    }
+
     switch (errno(system.fstat(fd, &stat))) {
         0 => return stat,
         EINVAL => unreachable,
@@ -2554,6 +2564,14 @@ pub const ClockGetTimeError = error{
 };
 
 pub fn clock_gettime(clk_id: i32, tp: *timespec) ClockGetTimeError!void {
+    if (netbsd.is_the_target) {
+        switch (errno(system.__clock_gettime50(ss, old_ss))) {
+            0 => return,
+            EFAULT => unreachable,
+            EINVAL => return error.UnsupportedClock,
+            else => |err| return unexpectedErrno(err),
+        }
+    }
     switch (errno(system.clock_gettime(clk_id, tp))) {
         0 => return,
         EFAULT => unreachable,
@@ -2563,6 +2581,14 @@ pub fn clock_gettime(clk_id: i32, tp: *t
 }
 
 pub fn clock_getres(clk_id: i32, res: *timespec) ClockGetTimeError!void {
+    if (netbsd.is_the_target) {
+        switch (errno(system.__clock_getres50(ss, old_ss))) {
+            0 => return,
+            EFAULT => unreachable,
+            EINVAL => return error.UnsupportedClock,
+            else => |err| return unexpectedErrno(err),
+        }
+    }
     switch (errno(system.clock_getres(clk_id, res))) {
         0 => return,
         EFAULT => unreachable,
@@ -2635,6 +2661,17 @@ pub fn sigaltstack(ss: ?*stack_t, old_ss
     if (windows.is_the_target or uefi.is_the_target or wasi.is_the_target)
         @compileError("std.os.sigaltstack not available for this target");
 
+    if (netbsd.is_the_target) {
+        switch (errno(system.__sigaltstack14(ss, old_ss))) {
+            0 => return,
+            EFAULT => unreachable,
+            EINVAL => unreachable,
+            ENOMEM => return error.SizeTooSmall,
+            EPERM => return error.PermissionDenied,
+            else => |err| return unexpectedErrno(err),
+        }
+    }
+
     switch (errno(system.sigaltstack(ss, old_ss))) {
         0 => return,
         EFAULT => unreachable,

$NetBSD: patch-std_os_time.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/os/time.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/os/time.zig
@@ -14,7 +14,7 @@ pub const epoch = @import("epoch.zig");
 /// Sleep for the specified duration
 pub fn sleep(nanoseconds: u64) void {
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             const s = nanoseconds / ns_per_s;
             const ns = nanoseconds % ns_per_s;
             posixSleep(@intCast(u63, s), @intCast(u63, ns));
@@ -62,7 +62,7 @@ pub fn timestamp() u64 {
 /// Get the posix timestamp, UTC, in milliseconds
 pub const milliTimestamp = switch (builtin.os) {
     Os.windows => milliTimestampWindows,
-    Os.linux, Os.freebsd => milliTimestampPosix,
+    Os.linux, Os.freebsd, Os.netbsd => milliTimestampPosix,
     Os.macosx, Os.ios => milliTimestampDarwin,
     else => @compileError("Unsupported OS"),
 };
@@ -178,7 +178,7 @@ pub const Timer = struct {
                 debug.assert(err != windows.FALSE);
                 self.start_time = @intCast(u64, start_time);
             },
-            Os.linux, Os.freebsd => {
+            Os.linux, Os.freebsd, Os.netbsd => {
                 //On Linux, seccomp can do arbitrary things to our ability to call
                 //  syscalls, including return any errno value it wants and
                 //  inconsistently throwing errors. Since we can't account for
@@ -214,7 +214,7 @@ pub const Timer = struct {
         var clock = clockNative() - self.start_time;
         return switch (builtin.os) {
             Os.windows => @divFloor(clock * ns_per_s, self.frequency),
-            Os.linux, Os.freebsd => clock,
+            Os.linux, Os.freebsd, Os.netbsd => clock,
             Os.macosx, Os.ios => @divFloor(clock * self.frequency.numer, self.frequency.denom),
             else => @compileError("Unsupported OS"),
         };
@@ -235,7 +235,7 @@ pub const Timer = struct {
 
     const clockNative = switch (builtin.os) {
         Os.windows => clockWindows,
-        Os.linux, Os.freebsd => clockLinux,
+        Os.linux, Os.freebsd, Os.netbsd => clockLinux,
         Os.macosx, Os.ios => clockDarwin,
         else => @compileError("Unsupported OS"),
     };

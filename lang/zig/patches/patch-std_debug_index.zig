$NetBSD: patch-std_debug_index.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/debug/index.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/debug/index.zig
@@ -240,7 +240,7 @@ pub fn writeCurrentStackTraceWindows(
 pub fn printSourceAtAddress(debug_info: *DebugInfo, out_stream: var, address: usize, tty_color: bool) !void {
     switch (builtin.os) {
         builtin.Os.macosx => return printSourceAtAddressMacOs(debug_info, out_stream, address, tty_color),
-        builtin.Os.linux, builtin.Os.freebsd => return printSourceAtAddressLinux(debug_info, out_stream, address, tty_color),
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => return printSourceAtAddressLinux(debug_info, out_stream, address, tty_color),
         builtin.Os.windows => return printSourceAtAddressWindows(debug_info, out_stream, address, tty_color),
         else => return error.UnsupportedOperatingSystem,
     }
@@ -717,7 +717,7 @@ pub const OpenSelfDebugInfoError = error
 
 pub fn openSelfDebugInfo(allocator: *mem.Allocator) !DebugInfo {
     switch (builtin.os) {
-        builtin.Os.linux, builtin.Os.freebsd => return openSelfDebugInfoLinux(allocator),
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => return openSelfDebugInfoLinux(allocator),
         builtin.Os.macosx, builtin.Os.ios => return openSelfDebugInfoMacOs(allocator),
         builtin.Os.windows => return openSelfDebugInfoWindows(allocator),
         else => return error.UnsupportedOperatingSystem,
@@ -1141,7 +1141,7 @@ pub const DebugInfo = switch (builtin.os
         sect_contribs: []pdb.SectionContribEntry,
         modules: []Module,
     },
-    builtin.Os.linux, builtin.Os.freebsd => DwarfInfo,
+    builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => DwarfInfo,
     else => @compileError("Unsupported OS"),
 };
 

$NetBSD: patch-src-self-hosted_libc__installation.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- src-self-hosted/libc_installation.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ src-self-hosted/libc_installation.zig
@@ -172,7 +172,7 @@ pub const LibCInstallation = struct {
                 try group.call(findNativeStaticLibDir, self, loop);
                 try group.call(findNativeDynamicLinker, self, loop);
             },
-            builtin.Os.macosx, builtin.Os.freebsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                 self.include_dir = try std.mem.dupe(loop.allocator, u8, "/usr/include");
             },
             else => @compileError("unimplemented: find libc for this OS"),

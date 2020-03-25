$NetBSD: patch-lib_std_fs.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- lib/std/fs.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/fs.zig
@@ -726,12 +726,10 @@ pub const Dir = struct {
                 }
 
                 while (true) {
-                    const rc = os.system.getdirentries(
-                        self.handle.fd,
-                        self.handle.buf.ptr,
-                        self.handle.buf.len,
-                        &self.handle.seek,
-                    );
+                    const rc = switch (builtin.os) {
+                        .netbsd => os.system.__getdents30(self.handle.fd, self.handle.buf.ptr, self.handle.buf.len),
+                        else => os.system.getdents(self.handle.fd, self.handle.buf.ptr, self.handle.buf.len)
+                    };
                     switch (os.errno(rc)) {
                         0 => {},
                         os.EBADF => unreachable,

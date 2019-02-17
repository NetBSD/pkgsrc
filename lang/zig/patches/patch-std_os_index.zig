$NetBSD: patch-std_os_index.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/os/index.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/os/index.zig
@@ -3,7 +3,7 @@ const builtin = @import("builtin");
 const Os = builtin.Os;
 const is_windows = builtin.os == Os.windows;
 const is_posix = switch (builtin.os) {
-    builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd => true,
+    builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => true,
     else => false,
 };
 const os = @This();
@@ -30,6 +30,7 @@ pub const windows = @import("windows/ind
 pub const darwin = @import("darwin.zig");
 pub const linux = @import("linux/index.zig");
 pub const freebsd = @import("freebsd/index.zig");
+pub const netbsd = @import("netbsd/index.zig");
 pub const zen = @import("zen.zig");
 pub const uefi = @import("uefi.zig");
 
@@ -37,6 +38,7 @@ pub const posix = switch (builtin.os) {
     Os.linux => linux,
     Os.macosx, Os.ios => darwin,
     Os.freebsd => freebsd,
+    Os.netbsd => netbsd,
     Os.zen => zen,
     else => @compileError("Unsupported OS"),
 };
@@ -50,7 +52,7 @@ pub const time = @import("time.zig");
 
 pub const page_size = 4 * 1024;
 pub const MAX_PATH_BYTES = switch (builtin.os) {
-    Os.linux, Os.macosx, Os.ios, Os.freebsd => posix.PATH_MAX,
+    Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => posix.PATH_MAX,
     // Each UTF-16LE character may be expanded to 3 UTF-8 bytes.
     // If it would require 4 UTF-8 bytes, then there would be a surrogate
     // pair in the UTF-16LE, and we (over)account 3 bytes for it that way.
@@ -125,7 +127,7 @@ pub fn getRandomBytes(buf: []u8) !void {
                 else => return unexpectedErrorPosix(errno),
             }
         },
-        Os.macosx, Os.ios, Os.freebsd => return getRandomBytesDevURandom(buf),
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => return getRandomBytesDevURandom(buf),
         Os.windows => {
             // Call RtlGenRandom() instead of CryptGetRandom() on Windows
             // https://github.com/rust-lang-nursery/rand/issues/111
@@ -185,7 +187,7 @@ pub fn abort() noreturn {
         c.abort();
     }
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             _ = posix.raise(posix.SIGABRT);
             _ = posix.raise(posix.SIGKILL);
             while (true) {}
@@ -211,7 +213,7 @@ pub fn exit(status: u8) noreturn {
         c.exit(status);
     }
     switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             posix.exit(status);
         },
         Os.windows => {
@@ -327,7 +329,7 @@ pub fn posix_preadv(fd: i32, iov: [*]con
                 }
             }
         },
-        builtin.Os.linux, builtin.Os.freebsd => while (true) {
+        builtin.Os.linux, builtin.Os.freebsd, Os.netbsd => while (true) {
             const rc = posix.preadv(fd, iov, count, offset);
             const err = posix.getErrno(rc);
             switch (err) {
@@ -434,7 +436,7 @@ pub fn posix_pwritev(fd: i32, iov: [*]co
                 }
             }
         },
-        builtin.Os.linux, builtin.Os.freebsd => while (true) {
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => while (true) {
             const rc = posix.pwritev(fd, iov, count, offset);
             const err = posix.getErrno(rc);
             switch (err) {
@@ -699,7 +701,7 @@ pub fn getBaseAddress() usize {
             const phdr = linuxGetAuxVal(std.elf.AT_PHDR);
             return phdr - @sizeOf(std.elf.Ehdr);
         },
-        builtin.Os.macosx, builtin.Os.freebsd => return @ptrToInt(&std.c._mh_execute_header),
+        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => return @ptrToInt(&std.c._mh_execute_header),
         builtin.Os.windows => return @ptrToInt(windows.GetModuleHandleW(null)),
         else => @compileError("Unsupported OS"),
     }
@@ -1339,7 +1341,7 @@ pub fn deleteDirC(dir_path: [*]const u8)
             const dir_path_w = try windows_util.cStrToPrefixedFileW(dir_path);
             return deleteDirW(&dir_path_w);
         },
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             const err = posix.getErrno(posix.rmdir(dir_path));
             switch (err) {
                 0 => return,
@@ -1382,7 +1384,7 @@ pub fn deleteDir(dir_path: []const u8) D
             const dir_path_w = try windows_util.sliceToPrefixedFileW(dir_path);
             return deleteDirW(&dir_path_w);
         },
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             const dir_path_c = try toPosixPath(dir_path);
             return deleteDirC(&dir_path_c);
         },
@@ -1501,7 +1503,7 @@ pub const Dir = struct {
     allocator: *Allocator,
 
     pub const Handle = switch (builtin.os) {
-        Os.macosx, Os.ios, Os.freebsd => struct {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => struct {
             fd: i32,
             seek: i64,
             buf: []u8,
@@ -1578,7 +1580,7 @@ pub const Dir = struct {
                         .name_data = undefined,
                     };
                 },
-                Os.macosx, Os.ios, Os.freebsd => Handle{
+                Os.macosx, Os.ios, Os.freebsd, Os.netbsd => Handle{
                     .fd = try posixOpen(
                         dir_path,
                         posix.O_RDONLY | posix.O_NONBLOCK | posix.O_DIRECTORY | posix.O_CLOEXEC,
@@ -1609,7 +1611,7 @@ pub const Dir = struct {
             Os.windows => {
                 _ = windows.FindClose(self.handle.handle);
             },
-            Os.macosx, Os.ios, Os.linux, Os.freebsd => {
+            Os.macosx, Os.ios, Os.linux, Os.freebsd, Os.netbsd => {
                 self.allocator.free(self.handle.buf);
                 os.close(self.handle.fd);
             },
@@ -1625,6 +1627,7 @@ pub const Dir = struct {
             Os.macosx, Os.ios => return self.nextDarwin(),
             Os.windows => return self.nextWindows(),
             Os.freebsd => return self.nextFreebsd(),
+            Os.netbsd => return self.nextFreebsd(),
             else => @compileError("unimplemented"),
         }
     }
@@ -2256,7 +2259,7 @@ pub fn unexpectedErrorWindows(err: windo
 pub fn openSelfExe() !os.File {
     switch (builtin.os) {
         Os.linux => return os.File.openReadC(c"/proc/self/exe"),
-        Os.macosx, Os.ios, Os.freebsd => {
+        Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             var buf: [MAX_PATH_BYTES]u8 = undefined;
             const self_exe_path = try selfExePath(&buf);
             buf[self_exe_path.len] = 0;
@@ -2317,6 +2320,19 @@ pub fn selfExePath(out_buffer: *[MAX_PAT
                 else => unexpectedErrorPosix(err),
             };
         },
+        Os.netbsd => {
+            var mib = [4]c_int{ posix.CTL_KERN, posix.KERN_PROC_ARGS, -1, posix.KERN_PROC_PATHNAME };
+            var out_len: usize = out_buffer.len;
+            const err = posix.getErrno(posix.sysctl(&mib, 4, out_buffer, &out_len, null, 0));
+
+            if (err == 0) return mem.toSlice(u8, out_buffer);
+
+            return switch (err) {
+                posix.EFAULT => error.BadAdress,
+                posix.EPERM => error.PermissionDenied,
+                else => unexpectedErrorPosix(err),
+            };
+        },
         Os.windows => {
             var utf16le_buf: [windows_util.PATH_MAX_WIDE]u16 = undefined;
             const utf16le_slice = try selfExePathW(&utf16le_buf);
@@ -2355,7 +2371,7 @@ pub fn selfExeDirPath(out_buffer: *[MAX_
             // will not return null.
             return path.dirname(full_exe_path).?;
         },
-        Os.windows, Os.macosx, Os.ios, Os.freebsd => {
+        Os.windows, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
             const self_exe_path = try selfExePath(out_buffer);
             // Assume that the OS APIs return absolute paths, and therefore dirname
             // will not return null.
@@ -3227,7 +3243,7 @@ pub const CpuCountError = error{
 
 pub fn cpuCount(fallback_allocator: *mem.Allocator) CpuCountError!usize {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.freebsd => {
+        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
             var count: c_int = undefined;
             var count_len: usize = @sizeOf(c_int);
             const rc = posix.sysctlbyname(switch (builtin.os) {

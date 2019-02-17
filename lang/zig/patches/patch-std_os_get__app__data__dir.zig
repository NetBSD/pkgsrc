$NetBSD: patch-std_os_get__app__data__dir.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/os/get_app_data_dir.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/os/get_app_data_dir.zig
@@ -43,7 +43,7 @@ pub fn getAppDataDir(allocator: *mem.All
             };
             return os.path.join(allocator, [][]const u8{ home_dir, "Library", "Application Support", appname });
         },
-        builtin.Os.linux, builtin.Os.freebsd => {
+        builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
             const home_dir = os.getEnvPosix("HOME") orelse {
                 // TODO look in /etc/passwd
                 return error.AppDataDirUnavailable;

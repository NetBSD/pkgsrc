$NetBSD: patch-std_os_get__user__id.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/os/get_user_id.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/os/get_user_id.zig
@@ -11,7 +11,7 @@ pub const UserInfo = struct {
 /// POSIX function which gets a uid from username.
 pub fn getUserInfo(name: []const u8) !UserInfo {
     return switch (builtin.os) {
-        Os.linux, Os.macosx, Os.ios, Os.freebsd => posixGetUserInfo(name),
+        Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => posixGetUserInfo(name),
         else => @compileError("Unsupported OS"),
     };
 }

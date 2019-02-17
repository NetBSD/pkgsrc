$NetBSD: patch-std_c_index.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/c/index.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/c/index.zig
@@ -6,6 +6,7 @@ pub use switch (builtin.os) {
     Os.windows => @import("windows.zig"),
     Os.macosx, Os.ios => @import("darwin.zig"),
     Os.freebsd => @import("freebsd.zig"),
+    Os.netbsd => @import("netbsd.zig"),
     else => empty_import,
 };
 const empty_import = @import("../empty.zig");

$NetBSD: patch-build.zig,v 1.1 2023/02/28 21:07:43 nikita Exp $

Fix PIE build.

--- build.zig.orig	2023-01-19 20:45:54.216372800 +0100
+++ build.zig	2023-01-19 20:46:23.795210635 +0100
@@ -10,6 +10,7 @@
     const exe = b.addExecutable("ncdu", "src/main.zig");
     exe.setTarget(target);
     exe.setBuildMode(mode);
+    exe.pie = true;
     exe.addCSourceFile("src/ncurses_refs.c", &[_][]const u8{});
     exe.linkLibC();
     exe.linkSystemLibrary("ncursesw");

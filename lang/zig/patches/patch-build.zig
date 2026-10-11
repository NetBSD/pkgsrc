$NetBSD: patch-build.zig,v 1.1 2026/10/11 06:41:44 adam Exp $

Install langref.html into correct path.

--- build.zig.orig	2026-10-11 06:29:17.097421286 +0000
+++ build.zig
@@ -38,7 +38,7 @@ pub fn build(b: *std.Build) !void {
     const enable_superhtml = b.option(bool, "enable-superhtml", "Check langref output HTML validity") orelse false;
 
     const langref_file = try generateLangRef(b);
-    const install_langref = b.addInstallFileWithDir(langref_file, .prefix, "doc/langref.html");
+    const install_langref = b.addInstallFileWithDir(langref_file, .prefix, "share/doc/zig/langref.html");
     const check_langref = superHtmlCheck(b, langref_file);
     if (enable_superhtml) install_langref.step.dependOn(check_langref);
 

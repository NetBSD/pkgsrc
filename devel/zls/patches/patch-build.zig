$NetBSD$

--- build.zig.orig	2025-03-17 06:46:13.317251024 +0000
+++ build.zig
@@ -41,9 +41,6 @@ pub fn build(b: *Build) !void {
     const enable_tracy_allocation = b.option(bool, "enable_tracy_allocation", "Enable using TracyAllocator to monitor allocations.") orelse enable_tracy;
     const enable_tracy_callstack = b.option(bool, "enable_tracy_callstack", "Enable callstack graphs.") orelse enable_tracy;
     const test_filters = b.option([]const []const u8, "test-filter", "Skip tests that do not match filter") orelse &[0][]const u8{};
-    const data_version = b.option([]const u8, "data_version", "The Zig version your compiler is.");
-    const data_version_path = b.option([]const u8, "version_data_path", "Manually specify zig language reference file");
-    const override_version_data_file_path = b.option([]const u8, "version_data_file_path", "Relative path to version data file (if none, will be named with timestamp)");
     const use_llvm = b.option(bool, "use_llvm", "Use Zig's llvm code backend");
 
     const resolved_zls_version = getVersion(b);
@@ -88,17 +85,31 @@ pub fn build(b: *Build) !void {
     const gen_exe = b.addExecutable(.{
         .name = "zls_gen",
         .root_source_file = b.path("src/config_gen/config_gen.zig"),
-        .target = b.host,
+        .target = b.graph.host,
         .single_threaded = true,
     });
 
+    const version_data_module = blk: {
+        const gen_version_data_cmd = b.addRunArtifact(gen_exe);
+        const version = if (zls_version.pre == null and zls_version.build == null) b.fmt("{}", .{zls_version}) else "master";
+        gen_version_data_cmd.addArgs(&.{ "--langref-version", version });
+
+        gen_version_data_cmd.addArg("--langref-path");
+        gen_version_data_cmd.addFileArg(b.path(b.fmt("src/tools/langref_{s}.html.in", .{version})));
+
+        gen_version_data_cmd.addArg("--generate-version-data");
+        const version_data_path = gen_version_data_cmd.addOutputFileArg("version_data.zig");
+
+        break :blk b.addModule("version_data", .{ .root_source_file = version_data_path });
+    };
+
     const gen_cmd = b.addRunArtifact(gen_exe);
     gen_cmd.addArgs(&.{
         "--readme-path",
         b.pathFromRoot("README.md"),
-        "--generate-config-path",
+        "--generate-config",
         b.pathFromRoot("src/Config.zig"),
-        "--generate-schema-path",
+        "--generate-schema",
         b.pathFromRoot("schema.json"),
     });
     if (b.args) |args| gen_cmd.addArgs(args);
@@ -106,28 +117,6 @@ pub fn build(b: *Build) !void {
     const gen_step = b.step("gen", "Regenerate config files");
     gen_step.dependOn(&gen_cmd.step);
 
-    const gen_version_data_cmd = b.addRunArtifact(gen_exe);
-    const resolved_data_version = data_version orelse if (zls_version.pre == null and zls_version.build == null) b.fmt("{}", .{zls_version}) else "master";
-    gen_version_data_cmd.addArgs(&.{ "--generate-version-data", resolved_data_version });
-    if (data_version_path) |path| {
-        gen_version_data_cmd.addArg("--langref_path");
-        gen_version_data_cmd.addFileArg(.{ .cwd_relative = path });
-    }
-    const version_data_file_name = if (data_version_path != null)
-        b.fmt("version_data_{s}.zig", .{resolved_data_version})
-    else blk: {
-        // invalidate version data periodically from cache because the website content may change
-        // setting `has_side_effects` would also be possible but that would always force a re-run
-        const timestamp = @divFloor(std.time.timestamp(), std.time.s_per_day);
-        break :blk b.fmt("version_data_{s}_{d}.zig", .{ resolved_data_version, timestamp });
-    };
-    gen_version_data_cmd.addArg("--generate-version-data-path");
-    const version_data_path: std.Build.LazyPath = if (override_version_data_file_path) |path|
-        .{ .cwd_relative = path }
-    else
-        gen_version_data_cmd.addOutputFileArg(version_data_file_name);
-    const version_data_module = b.addModule("version_data", .{ .root_source_file = version_data_path });
-
     const zls_module = b.addModule("zls", .{
         .root_source_file = b.path("src/zls.zig"),
         .imports = &.{

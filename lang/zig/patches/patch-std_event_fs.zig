$NetBSD: patch-std_event_fs.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/event/fs.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/event/fs.zig
@@ -85,6 +85,7 @@ pub async fn pwritev(loop: *Loop, fd: os
         builtin.Os.macosx,
         builtin.Os.linux,
         builtin.Os.freebsd,
+        builtin.Os.netbsd,
         => {
             const iovecs = try loop.allocator.alloc(os.posix.iovec_const, data.len);
             defer loop.allocator.free(iovecs);
@@ -222,6 +223,7 @@ pub async fn preadv(loop: *Loop, fd: os.
         builtin.Os.macosx,
         builtin.Os.linux,
         builtin.Os.freebsd,
+        builtin.Os.netbsd,
         => {
             const iovecs = try loop.allocator.alloc(os.posix.iovec, data.len);
             defer loop.allocator.free(iovecs);
@@ -402,7 +404,11 @@ pub async fn openPosix(
 
 pub async fn openRead(loop: *Loop, path: []const u8) os.File.OpenError!os.FileHandle {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd => {
+        builtin.Os.macosx,
+        builtin.Os.linux,
+        builtin.Os.freebsd,
+        builtin.Os.netbsd
+        => {
             const flags = posix.O_LARGEFILE | posix.O_RDONLY | posix.O_CLOEXEC;
             return await (async openPosix(loop, path, flags, os.File.default_mode) catch unreachable);
         },
@@ -431,6 +437,7 @@ pub async fn openWriteMode(loop: *Loop, 
         builtin.Os.macosx,
         builtin.Os.linux,
         builtin.Os.freebsd,
+        builtin.Os.netbsd,
         => {
             const flags = posix.O_LARGEFILE | posix.O_WRONLY | posix.O_CREAT | posix.O_CLOEXEC | posix.O_TRUNC;
             return await (async openPosix(loop, path, flags, os.File.default_mode) catch unreachable);
@@ -453,7 +460,7 @@ pub async fn openReadWrite(
     mode: os.File.Mode,
 ) os.File.OpenError!os.FileHandle {
     switch (builtin.os) {
-        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd => {
+        builtin.Os.macosx, builtin.Os.linux, builtin.Os.freebsd, builtin.Os.netbsd => {
             const flags = posix.O_LARGEFILE | posix.O_RDWR | posix.O_CREAT | posix.O_CLOEXEC;
             return await (async openPosix(loop, path, flags, mode) catch unreachable);
         },
@@ -481,7 +488,7 @@ pub const CloseOperation = struct {
     os_data: OsData,
 
     const OsData = switch (builtin.os) {
-        builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd => OsDataPosix,
+        builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => OsDataPosix,
 
         builtin.Os.windows => struct {
             handle: ?os.FileHandle,
@@ -500,7 +507,7 @@ pub const CloseOperation = struct {
         self.* = CloseOperation{
             .loop = loop,
             .os_data = switch (builtin.os) {
-                builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd => initOsDataPosix(self),
+                builtin.Os.linux, builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => initOsDataPosix(self),
                 builtin.Os.windows => OsData{ .handle = null },
                 else => @compileError("Unsupported OS"),
             },
@@ -530,6 +537,7 @@ pub const CloseOperation = struct {
             builtin.Os.linux,
             builtin.Os.macosx,
             builtin.Os.freebsd,
+            builtin.Os.netbsd,
             => {
                 if (self.os_data.have_fd) {
                     self.loop.posixFsRequest(&self.os_data.close_req_node);
@@ -552,6 +560,7 @@ pub const CloseOperation = struct {
             builtin.Os.linux,
             builtin.Os.macosx,
             builtin.Os.freebsd,
+            builtin.Os.netbsd,
             => {
                 self.os_data.close_req_node.data.msg.Close.fd = handle;
                 self.os_data.have_fd = true;
@@ -569,6 +578,7 @@ pub const CloseOperation = struct {
             builtin.Os.linux,
             builtin.Os.macosx,
             builtin.Os.freebsd,
+            builtin.Os.netbsd,
             => {
                 self.os_data.have_fd = false;
             },
@@ -584,6 +594,7 @@ pub const CloseOperation = struct {
             builtin.Os.linux,
             builtin.Os.macosx,
             builtin.Os.freebsd,
+            builtin.Os.netbsd,
             => {
                 assert(self.os_data.have_fd);
                 return self.os_data.close_req_node.data.msg.Close.fd;
@@ -608,6 +619,7 @@ pub async fn writeFileMode(loop: *Loop, 
         builtin.Os.linux,
         builtin.Os.macosx,
         builtin.Os.freebsd,
+        builtin.Os.netbsd,
         => return await (async writeFileModeThread(loop, path, contents, mode) catch unreachable),
         builtin.Os.windows => return await (async writeFileWindows(loop, path, contents) catch unreachable),
         else => @compileError("Unsupported OS"),
@@ -713,7 +725,7 @@ pub fn Watch(comptime V: type) type {
         os_data: OsData,
 
         const OsData = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd => struct {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => struct {
                 file_table: FileTable,
                 table_lock: event.Lock,
 
@@ -802,7 +814,7 @@ pub fn Watch(comptime V: type) type {
                     return self;
                 },
 
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     const self = try loop.allocator.create(Self);
                     errdefer loop.allocator.destroy(self);
 
@@ -822,7 +834,7 @@ pub fn Watch(comptime V: type) type {
         /// All addFile calls and removeFile calls must have completed.
         pub fn destroy(self: *Self) void {
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     // TODO we need to cancel the coroutines before destroying the lock
                     self.os_data.table_lock.deinit();
                     var it = self.os_data.file_table.iterator();
@@ -864,7 +876,10 @@ pub fn Watch(comptime V: type) type {
 
         pub async fn addFile(self: *Self, file_path: []const u8, value: V) !?V {
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd => return await (async addFileKEvent(self, file_path, value) catch unreachable),
+                builtin.Os.macosx,
+                builtin.Os.freebsd,
+                builtin.Os.netbsd
+                => return await (async addFileKEvent(self, file_path, value) catch unreachable),
                 builtin.Os.linux => return await (async addFileLinux(self, file_path, value) catch unreachable),
                 builtin.Os.windows => return await (async addFileWindows(self, file_path, value) catch unreachable),
                 else => @compileError("Unsupported OS"),

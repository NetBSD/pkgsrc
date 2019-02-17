$NetBSD: patch-std_event_loop.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/event/loop.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/event/loop.zig
@@ -50,7 +50,7 @@ pub const Loop = struct {
         };
 
         pub const EventFd = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd => KEventFd,
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventFd,
             builtin.Os.linux => struct {
                 base: ResumeNode,
                 epoll_op: u32,
@@ -69,7 +69,7 @@ pub const Loop = struct {
         };
 
         pub const Basic = switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd => KEventBasic,
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventBasic,
             builtin.Os.linux => struct {
                 base: ResumeNode,
             },
@@ -221,7 +221,7 @@ pub const Loop = struct {
                     self.extra_threads[extra_thread_index] = try os.spawnThread(self, workerRun);
                 }
             },
-            builtin.Os.macosx, builtin.Os.freebsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                 self.os_data.kqfd = try os.bsdKQueue();
                 errdefer os.close(self.os_data.kqfd);
 
@@ -386,7 +386,7 @@ pub const Loop = struct {
                 os.close(self.os_data.epollfd);
                 self.allocator.free(self.eventfd_resume_nodes);
             },
-            builtin.Os.macosx, builtin.Os.freebsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                 os.close(self.os_data.kqfd);
                 os.close(self.os_data.fs_kqfd);
             },
@@ -501,7 +501,7 @@ pub const Loop = struct {
             const eventfd_node = &resume_stack_node.data;
             eventfd_node.base.handle = next_tick_node.data;
             switch (builtin.os) {
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     const kevent_array = (*[1]posix.Kevent)(&eventfd_node.kevent);
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                     _ = os.bsdKEvent(self.os_data.kqfd, kevent_array, empty_kevs, null) catch {
@@ -564,6 +564,7 @@ pub const Loop = struct {
             builtin.Os.linux,
             builtin.Os.macosx,
             builtin.Os.freebsd,
+            builtin.Os.netbsd,
             => self.os_data.fs_thread.wait(),
             else => {},
         }
@@ -628,7 +629,7 @@ pub const Loop = struct {
                     os.posixWrite(self.os_data.final_eventfd, wakeup_bytes) catch unreachable;
                     return;
                 },
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     self.posixFsRequest(&self.os_data.fs_end_request);
                     const final_kevent = (*[1]posix.Kevent)(&self.os_data.final_kevent);
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
@@ -686,7 +687,7 @@ pub const Loop = struct {
                         }
                     }
                 },
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     var eventlist: [1]posix.Kevent = undefined;
                     const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                     const count = os.bsdKEvent(self.os_data.kqfd, empty_kevs, eventlist[0..], null) catch unreachable;
@@ -749,7 +750,7 @@ pub const Loop = struct {
         self.beginOneEvent(); // finished in posixFsRun after processing the msg
         self.os_data.fs_queue.put(request_node);
         switch (builtin.os) {
-            builtin.Os.macosx, builtin.Os.freebsd => {
+            builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                 const fs_kevs = (*[1]posix.Kevent)(&self.os_data.fs_kevent_wake);
                 const empty_kevs = ([*]posix.Kevent)(undefined)[0..0];
                 _ = os.bsdKEvent(self.os_data.fs_kqfd, fs_kevs, empty_kevs, null) catch unreachable;
@@ -819,7 +820,7 @@ pub const Loop = struct {
                         else => unreachable,
                     }
                 },
-                builtin.Os.macosx, builtin.Os.freebsd => {
+                builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => {
                     const fs_kevs = (*[1]posix.Kevent)(&self.os_data.fs_kevent_wait);
                     var out_kevs: [1]posix.Kevent = undefined;
                     _ = os.bsdKEvent(self.os_data.fs_kqfd, fs_kevs, out_kevs[0..], null) catch unreachable;
@@ -831,7 +832,7 @@ pub const Loop = struct {
 
     const OsData = switch (builtin.os) {
         builtin.Os.linux => LinuxOsData,
-        builtin.Os.macosx, builtin.Os.freebsd => KEventData,
+        builtin.Os.macosx, builtin.Os.freebsd, builtin.Os.netbsd => KEventData,
         builtin.Os.windows => struct {
             io_port: windows.HANDLE,
             extra_thread_count: usize,

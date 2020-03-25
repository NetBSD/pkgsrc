$NetBSD: patch-lib_std_thread.zig,v 1.1 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- lib/std/thread.zig.orig	2019-09-30 15:40:00.000000000 +0000
+++ lib/std/thread.zig
@@ -255,12 +255,13 @@ pub const Thread = struct {
             }
             break :blk l;
         };
-        // Map the whole stack with no rw permissions to avoid committing the
-        // whole region right away
+        // NetBSD mprotect is very strict and doesn't allow to "upgrade"
+        // a PROT_NONE mapping to a RW one so let's allocate everything
+        // right away
         const mmap_slice = os.mmap(
             null,
-            mem.alignForward(mmap_len, mem.page_size),
-            os.PROT_NONE,
+            mmap_len,
+            os.PROT_READ | os.PROT_WRITE,
             os.MAP_PRIVATE | os.MAP_ANONYMOUS,
             -1,
             0,
@@ -272,10 +273,10 @@ pub const Thread = struct {
         };
         errdefer os.munmap(mmap_slice);
 
-        // Map everything but the guard page as rw
+        // Remap the guard page with no permissions
         os.mprotect(
-            mmap_slice,
-            os.PROT_READ | os.PROT_WRITE,
+            mmap_slice[0..guard_end_offset],
+            os.PROT_NONE,
         ) catch |err| switch (err) {
             error.AccessDenied => unreachable,
             else => |e| return e,
@@ -301,6 +302,12 @@ pub const Thread = struct {
 
             assert(c.pthread_attr_setstack(&attr, mmap_slice.ptr, stack_end_offset) == 0);
 
+            // Even though pthread's man pages state that the guard size is
+            // ignored when the stack address is explicitly given, on some
+            // plaforms such as NetBSD we still have to zero it to prevent
+            // random crashes in pthread_join calls
+            assert(c.pthread_attr_setguardsize(&attr, 0) == 0);
+
             const err = c.pthread_create(&thread_ptr.data.handle, &attr, MainFuncs.posixThreadMain, @intToPtr(*c_void, arg));
             switch (err) {
                 0 => return thread_ptr,

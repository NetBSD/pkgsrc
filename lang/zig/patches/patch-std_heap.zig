$NetBSD: patch-std_heap.zig,v 1.1 2019/02/17 12:33:40 maya Exp $

--- std/heap.zig.orig	2019-02-17 10:28:53.000000000 +0000
+++ std/heap.zig
@@ -71,7 +71,7 @@ pub const DirectAllocator = struct {
         const self = @fieldParentPtr(DirectAllocator, "allocator", allocator);
 
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 const p = os.posix;
                 const alloc_size = if (alignment <= os.page_size) n else n + alignment;
                 const addr = p.mmap(null, alloc_size, p.PROT_READ | p.PROT_WRITE, p.MAP_PRIVATE | p.MAP_ANONYMOUS, -1, 0);
@@ -120,7 +120,7 @@ pub const DirectAllocator = struct {
         const self = @fieldParentPtr(DirectAllocator, "allocator", allocator);
 
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 if (new_size <= old_mem.len) {
                     const base_addr = @ptrToInt(old_mem.ptr);
                     const old_addr_end = base_addr + old_mem.len;
@@ -164,7 +164,7 @@ pub const DirectAllocator = struct {
         const self = @fieldParentPtr(DirectAllocator, "allocator", allocator);
 
         switch (builtin.os) {
-            Os.linux, Os.macosx, Os.ios, Os.freebsd => {
+            Os.linux, Os.macosx, Os.ios, Os.freebsd, Os.netbsd => {
                 _ = os.posix.munmap(@ptrToInt(bytes.ptr), bytes.len);
             },
             Os.windows => {
